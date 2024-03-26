#include<stdio.h>

int main() {
    int queue[] = {98, 183, 37, 122, 14, 124, 65, 67}; // Request queue
    int head_position = 53; // Initial head position
    int total_movement = 0, direction = 1; // 1 for moving towards higher cylinders, -1 for lower

    printf("Head movement sequence: %d", head_position);

    // Sorting the request queue in ascending order
    for (int i = 0; i < sizeof(queue)/sizeof(queue[0]); i++) {
        for (int j = i+1; j < sizeof(queue)/sizeof(queue[0]); j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    while (1) {
        for (int i = 0; i < sizeof(queue)/sizeof(queue[0]); i++) {
            if ((direction == 1 && queue[i] >= head_position) || (direction == -1 && queue[i] <= head_position)) {
                total_movement += queue[i] - head_position; // Calculate movement without using abs
                head_position = queue[i];
                printf(" -> %d", head_position);
            }
        }
        if (direction == 1) { // If moving towards higher cylinders
            total_movement += 199 - head_position;
            head_position = 0; // Move to the beginning
            printf(" -> 0");
        }
        direction = -1; // Change direction
        if (head_position == 0) // Break out of loop when reached the beginning
            break;
    }

    printf("\nTotal head movement: %d\n", total_movement);

    return 0;
}

