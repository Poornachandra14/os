#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread function is running\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);
    pthread_join(thread_id, NULL);
    printf("Main thread exiting\n");
    return 0;
}

