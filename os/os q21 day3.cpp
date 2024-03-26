#include <stdio.h>

#define MEMORY_SIZE 1000
#define NUM_BLOCKS 5

int memory[MEMORY_SIZE];

void worst_fit(int process_size) {
    int max_hole_size = 0;
    int max_hole_index = -1;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0) {
            int hole_size = 0;
            int j = i;
            while (memory[j] == 0 && j < MEMORY_SIZE) {
                hole_size++;
                j++;
            }
            if (hole_size > max_hole_size) {
                max_hole_size = hole_size;
                max_hole_index = i;
            }
            i = j;
        }
    }

    if (max_hole_index != -1 && max_hole_size >= process_size) {
        for (int i = max_hole_index; i < max_hole_index + process_size; i++) {
            memory[i] = 1;
        }
        printf("Process of size %d allocated at memory location %d\n", process_size, max_hole_index);
    } else {
        printf("Memory allocation failed for process of size %d\n", process_size);
    }
}

int main() {
    // Initialize memory blocks
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }

    // Simulate memory allocation requests
    int processes[NUM_BLOCKS] = {200, 400, 150, 800, 300};
    for (int i = 0; i < NUM_BLOCKS; i++) {
        worst_fit(processes[i]);
    }

    return 0;
}

