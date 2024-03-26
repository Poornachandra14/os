#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Inside the thread function\n");
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread_function, NULL);
    pthread_create(&tid2, NULL, thread_function, NULL);
    
    if (pthread_equal(tid1, tid2)) {
        printf("Threads are equal\n");
    } else {
        printf("Threads are not equal\n");
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    return 0;
}

