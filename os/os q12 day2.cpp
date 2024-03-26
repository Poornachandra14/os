#include <stdio.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5
pthread_mutex_t forks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *((int *)arg);
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;
    while(1) {
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d is eating\n", id);
        pthread_mutex_unlock(&forks[right_fork]);
        pthread_mutex_unlock(&forks[left_fork]);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_create(&threads[i], NULL, philosopher, &i);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
    }
    return 0;
}

