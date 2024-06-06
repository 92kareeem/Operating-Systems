#include <stdio.h>
#include <pthread.h>
	
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_counter = 0;

void *thread_function(void *arg) {
    int i;
    for (i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        shared_counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int i;
    for (i = 0; i < 2; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, NULL);
    }

    for (i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    printf("Shared Counter: %d\n", shared_counter);

    return 0;
}

