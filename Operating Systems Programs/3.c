#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread function %d is running\n", *(int *)arg);
    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int thread_args[2] = {1, 2};
    int i;
    for ( i = 0; i < 2; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, &thread_args[i]);
    }
    for ( i = 0; i < 2; i++) {
        pthread_join(thread_id[i], NULL);
    }
    printf("Main thread is exiting\n");
    return 0;
}

