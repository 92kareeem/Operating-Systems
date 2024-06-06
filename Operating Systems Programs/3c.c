#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *thread_function(void *arg) {
    while (1) {
        printf("Thread is running\n");
        sleep(1);
    }
    return NULL;
}
int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);
    sleep(5);
    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);
    printf("Thread terminated\n");
    return 0;
} 
