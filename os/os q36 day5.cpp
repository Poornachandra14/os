#include <stdio.h>
#include <stdlib.h>

// Define the structure for disk block
typedef struct Block {
    int data;
    struct Block* next;
} Block;

// Function to initialize a new disk block
Block* createBlock(int data) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    newBlock->data = data;
    newBlock->next = NULL;
    return newBlock;
}

int main() {
    // Simulating directory entries pointing to the first and last blocks
    Block* firstBlock = createBlock(1); // First block of the file
    Block* lastBlock = firstBlock;      // Last block initially same as first

    // Simulating file blocks linked together
    lastBlock->next = createBlock(2);
    lastBlock = lastBlock->next;
    lastBlock->next = createBlock(3);
    lastBlock = lastBlock->next;
    lastBlock->next = createBlock(4);

    // Simulating accessing file blocks through traversal
    printf("Accessing file blocks...\n");
    Block* currentBlock = firstBlock;
    while (currentBlock != NULL) {
        printf("Block data: %d\n", currentBlock->data);
        currentBlock = currentBlock->next;
    }

    // Freeing allocated memory
    currentBlock = firstBlock;
    while (currentBlock != NULL) {
        Block* nextBlock = currentBlock->next;
        free(currentBlock);
        currentBlock = nextBlock;
    }

    return 0;
}

