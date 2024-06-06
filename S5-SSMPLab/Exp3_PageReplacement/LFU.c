#include <stdio.h>
#include <limits.h>
#define FRAME_SIZE 3

// Function to print the contents of the frames
void printFrames(int frames[], int size) {
    for (int i = 0; i < size; i++) {
        if (frames[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

// Function to check if a page fault occurred
int isPageFault(int frames[], int size, int page) {
    for (int i = 0; i < size; i++) {
        if (frames[i] == page) {
            return 0; // Page found in frames, no page fault
        }
    }
    return 1; // Page not found in frames, page fault occurred
}

// Function to get the least frequently used page from the frames
// Example
// Frames: [1, 2, 3]
// Counts: [2, 3, 1]
// 1 is the least count here, so the LFU is its corresponding frame which is 3

int getLFUPage(int frames[], int counts[], int size) {
    int lfuIndex = 0; // Setting least frequently used index to 0
    int minCount = INT_MAX; // Setting the minimum count found so far to the 
    for (int i = 0; i < size; i++) {
        if (counts[i] < minCount) {
            minCount = counts[i]; // Sets the least count
            lfuIndex = i;
        }
    }
    return frames[lfuIndex]; // Return the least frequently used page
}

// Function to update the count of a page in the frames
void updatePageCount(int pages[], int counts[], int size, int page) {
    for (int i = 0; i < size; i++) {
        if (pages[i] == page) {
            counts[i]++; // Increment the count for the page
            break;
        }
    }
}

// Function to perform LFU page replacement
void lfuPageReplacement(int pages[], int numPages) {
    int frames[FRAME_SIZE]; // Frames to hold the pages
    int counts[FRAME_SIZE]; // Count of each page in the frames
    int pageFaults = 0; // Counter for page faults

    // Initialize frames and counts with default values
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1; // -1 represents an empty frame
        counts[i] = 0; // Initialize count to 0 for each frame
    }

    printf("Page Faults: \n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d: ", pages[i]);

        if (isPageFault(frames, FRAME_SIZE, pages[i])) {
            int lfuPage = getLFUPage(frames, counts, FRAME_SIZE); // Find the least frequently used page
            int pageIndex = -1;

            // Find the index of the least frequently used page in frames
            for (int j = 0; j < FRAME_SIZE; j++) {
                if (frames[j] == lfuPage) {
                    pageIndex = j;
                    break;
                }
            }

            frames[pageIndex] = pages[i]; // Replace the least frequently used page with the new page
            counts[pageIndex] = 1; // Reset the count for the new page
            pageFaults++; // Increment the page fault count
            printFrames(frames, FRAME_SIZE); // Print the updated frames
        } else {
            updatePageCount(frames, counts, FRAME_SIZE, pages[i]); // Update the count for the existing page
            printf("No page fault occurred.\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 2, 3, 4, 5, 3, 1, 6, 7, 8, 7, 8, 9, 3, 9, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    lfuPageReplacement(pages, numPages); // Perform LFU page replacement
    return 0;
}