#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1 = (int *)malloc(sizeof(int)); // First-fit allocation
    printf("Memory allocated using malloc\n");
    
    int *ptr2 = (int *)calloc(1, sizeof(int)); // Best-fit allocation
    printf("Memory allocated using calloc\n");
    
    int *ptr3 = (int *)realloc(NULL, sizeof(int)); // Worst-fit allocation
    printf("Memory allocated using realloc\n");
    
    free(ptr1);
    printf("Memory freed from ptr1\n");
    
    free(ptr2);
    printf("Memory freed from ptr2\n");
    
    free(ptr3);
    printf("Memory freed from ptr3\n");
    
    return 0;
}

