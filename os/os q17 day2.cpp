#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES] = {3, 3, 2};
int max[MAX_PROCESSES][MAX_RESOURCES] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
int need[MAX_PROCESSES][MAX_RESOURCES];

bool is_safe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES];
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < MAX_PROCESSES; i++) {
        finish[i] = false;
        for (int j = 0; j < MAX_RESOURCES; j++) {
            if (allocation[i][j] != 0) {
                break;
            }
            if (j == MAX_RESOURCES - 1) {
                finish[i] = true;
            }
        }
    }
    int count = 0;
    while (count < MAX_PROCESSES) {
        bool found = false;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < MAX_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            return false; // System is in an unsafe state
        }
    }
    return true; // System is in a safe state
}

int main() {
    // Calculate need matrix
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    if (is_safe()) {
        printf("System is in a safe state.\n");
    } else {
        printf("System is in an unsafe state.\n");
    }

    return 0;
}

