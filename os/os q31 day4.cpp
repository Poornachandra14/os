#include<stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 15

int main() {
    int reference_string[MAX_PAGES] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4, 2, 3, 1};
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int frame_index = 0;
    int i, j;

    for (i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1; // Initialize frames with -1 indicating empty frame

    printf("Reference String: ");
    for (i = 0; i < MAX_PAGES; i++)
        printf("%d ", reference_string[i]);
    printf("\n");

    for (i = 0; i < MAX_PAGES; i++) {
        int page = reference_string[i];
        int page_found = 0;

        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            page_faults++;
            frames[frame_index] = page;
            frame_index = (frame_index + 1) % MAX_FRAMES;

            printf("Page %d caused a page fault. Frames: ", page);
            for (j = 0; j < MAX_FRAMES; j++)
                printf("%d ", frames[j]);
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

