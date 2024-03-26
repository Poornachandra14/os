#include <stdio.h>

#define MEMORY_SIZE 1000
#define NUM_BLOCKS 5

int memory[MEMORY_SIZE];

void first_fit(int process_size) {
    int i = 0;
    int hole_size = 0;
    int hole_start = -1;

    while (i < MEMORY_SIZE) {
        if (memory[i] == 0) {
            if (hole_start == -1) {
                hole_start = i;
            }
            hole_size++;
        } else {
            if (hole_size >= process_size) {
                for (int j = hole_start; j < hole_start + process_size; j++) {
                    memory[j] = 1;
                }
                printf("Process of size %d allocated at memory location %d\n", process_size, hole_start);
                return;
            }
            hole_size = 0;
            hole_start = -1;
        }
        i++;
    }

    printf("Memory allocation failed for process of size %d\n", process_size);
}

int main() {
    // Initialize memory blocks
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }

    // Simulate memory allocation requests
    int processes[NUM_BLOCKS] = {200, 400, 150, 800, 300};
    for (int i = 0; i < NUM_BLOCKS; i++) {
        first_fit(processes[i]);
    }

    return 0;
}

