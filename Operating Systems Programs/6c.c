#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_READERS 3
#define NUM_WRITERS 2
int shared_data = 0;
int readers_count = 0;
sem_t mutex;          
sem_t rw_mutex;       
sem_t readers_mutex;  
void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        sem_wait(&readers_mutex);
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);
        sem_post(&readers_mutex);

        
        printf("Reader %d is reading: %d\n", reader_id, shared_data);
        usleep(1000000); 

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);
        usleep(1000000); 
    }
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        sem_wait(&rw_mutex);
        shared_data++;
        printf("Writer %d is writing: %d\n", writer_id, shared_data);
        usleep(2000000); 
        sem_post(&rw_mutex);
        usleep(1000000);
    }
}

int main() {
    pthread_t reader_threads[NUM_READERS];
    pthread_t writer_threads[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);
    sem_init(&readers_mutex, 0, 1);

    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
    }
   
    sleep(10);
   
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_cancel(reader_threads[i]);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_cancel(writer_threads[i]);
    }
    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);
    sem_destroy(&readers_mutex);
    return 0;
}

