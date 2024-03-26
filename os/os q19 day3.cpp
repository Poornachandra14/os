#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3

pthread_mutex_t mutex;
int shared_variable = 0;

void *thread_function(void *arg) {
    pthread_mutex_lock(&mutex);
    shared_variable++;
    printf("Thread %d incremented the shared variable to %d\n", *((int *)arg), shared_variable);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}

