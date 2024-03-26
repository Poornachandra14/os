#include<stdio.h>
#include<stdlib.h> // Include stdlib.h for abs function

int main() {
    int queue[] = {98, 183, 37, 122, 14, 124, 65, 67}; // Request queue
    int head_position = 53; // Initial head position
    int total_movement = 0;

    printf("Head movement sequence: %d", head_position);
    for (int i = 0; i < sizeof(queue)/sizeof(queue[0]); i++) {
        total_movement += abs(queue[i] - head_position);
        head_position = queue[i];
        printf(" -> %d", head_position);
    }

    printf("\nTotal head movement: %d\n", total_movement);

    return 0;
}

