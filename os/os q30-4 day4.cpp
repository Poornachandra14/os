#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    sleep(2);
    printf("Exiting thread\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_function, NULL);
    printf("Main thread continuing...\n");
    pthread_join(tid, NULL);
    printf("Main thread exiting\n");
    return 0;
}

