#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0, pageHits = 0, currentIndex = 0;
    int frameFull = 0;

    // Initialize frames to - indicating empty
    for (int i = 0; i < frameSize; i++) {
        frames[i] = '-';
    }

    // Iterate through the reference string
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == page) {
                pageHits++;
                pageFound = 1;
                break;
            }
        }

        // If the page is not in a frame, replace the oldest page
        if (!pageFound) {
            frames[currentIndex] = page;
            currentIndex = (currentIndex + 1) % frameSize;
            pageFaults++;

            if (!frameFull) {
                // If frames are not yet full, mark the next frame to be filled
                if (currentIndex == 0)
                    frameFull = 1;
            }
        }

        // Print the current state of frames for each reference
        printf("Page %2d: [", page);
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == '-')
                printf("-");
            else
                printf("%d", frames[j]);

            if (j < frameSize - 1)
                printf(", ");
        }
        printf("]\n");
    }

    // Calculate and print results
    double hitRatio = (double)pageHits / n;
    printf("\nNumber of Page Faults: %d\n", pageFaults);
    printf("Number of Page Hits: %d\n", pageHits);
    printf("Hit Ratio: %.2f\n", hitRatio);
}

int main() {
    int n, frameSize;

    // Input total number of pages
    printf("Enter the total number of pages: ");
    scanf("%d", &n);

    // Input frame size
    printf("Enter the frame size: ");
    scanf("%d", &frameSize);

    int pages[n];

    // Input reference string
    printf("Enter the reference string:\n");
    for (int i = 0; i < n; i++) {
        printf("Page %2d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    // Perform FIFO page replacement
    fifoPageReplacement(pages, n, frameSize);

    return 0;
}

