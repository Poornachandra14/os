#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Inside the thread function\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_function, NULL);
    printf("Thread created\n");
    pthread_join(tid, NULL); // Wait for the thread to finish
    return 0;
}

