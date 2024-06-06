#include <stdio.h>

#define FRAME_SIZE 3

// Function to print the frames
void printFrames(int frames[], int size){
    for(int i=0;i<size;i++){
        if(frames[i] == -1){
            printf("-");
        }
        else{
            printf("%d",frames[i]);
        }
    }
    printf("\n");
}

// Function to check if a page is a page fault
int isPageFault(int frames[], int size, int page){
    for(int i=0;i<size;i++){
        if(frames[i] == page){
            return 0; // Page found in the frames, no page fault
        }
    }
    return 1; // Page not found in the frames, page fault
}

// Function to get the least recently used page from the frames
int getLRUPage(int frames[], int pageIndices[], int size){ //finds the frame with the minimum page index in the pageIndices array
                                                         //and returns the corresponding page value from the frames array.(This is the LRU PAGE)                                               
    int lruIndex = 0;
    for(int i=1;i<size;i++){
        if(pageIndices[i] < pageIndices[lruIndex]){
            lruIndex = i; // Update the index of the least recently used page
        }
    }
    return frames[lruIndex]; // Return the value of the least recently used page
}


// Function to update the page indices after a page is accessed
// Example, Suppose we access the page index 1
// Before: pageIndices: [2, 3, 1]
// After: pageIndices: [3, 0, 2]
// 0 Signifies the page index 1 is the most recently used

void updatePageIndices(int pageIndices[], int size, int pageIndex){
    for(int i=0;i<size;i++){
        if(pageIndices[i] != -1){ // Checks if its an empty frame which has page index of -1
            pageIndices[i]++; // Increment the page index if it is not -1, This signifies the page has been updated recently
        }
    }
    pageIndices[pageIndex] = 0; // Set the page index of the recently accessed page to 0
}

// Function to perform LRU page replacement
void lruPageReplacement(int pages[], int numPages){
    int frames[FRAME_SIZE]; // Array to store the frames
    int pageIndices[FRAME_SIZE]; // Array to store the page indices
    int pageFaults = 0; // Counter for page faults

    // Initialize frames and page indices with -1
    for(int i=0;i<FRAME_SIZE;i++){
        frames[i] = -1;
        pageIndices[i] = -1;
    }


    printf("Page Faults\n");
    for(int i=0; i<numPages;i++){
        printf("Page %d:", pages[i]);

        if(isPageFault(frames, FRAME_SIZE, pages[i])){ // Check if current page is a page fault
            int lruPage = getLRUPage(frames, pageIndices, FRAME_SIZE); // If its a page fault, least recently used page is searched
            int pageIndex = -1;

            // Find the index of the least recently used page in the frames
            for(int j=0; j<FRAME_SIZE; j++){  
                if(frames[j] == lruPage){
                    pageIndex = j; // Store the index of the least recently used page
                    break;
                }
            }

            frames[pageIndex] = pages[i]; // Replace the least recently used page with the current page
            updatePageIndices(pageIndices, FRAME_SIZE, pageIndex); // Update the page indices

            pageFaults++; // Increment the page fault count
            printFrames(frames, FRAME_SIZE); // Print the current state of the frames
        }
        else{
            updatePageIndices(pageIndices, FRAME_SIZE, i); // Update the page indices
            printf("No page fault occurred\n");
        }
    }

    printf("Total page faults: %d\n", pageFaults);
}

int main(){
    int pages[] = {1, 2, 3, 4, 5, 3, 1, 6, 7, 8, 7, 8, 9, 3, 9, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    lruPageReplacement(pages, numPages);
    return 0;
}