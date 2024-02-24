#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void sortRequests(int requests[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
}

void cscan(int requests[], int n, int head, int diskSize) {
    int totalSeekTime = 0;
    int currentIndex, i;
    int upperBound = diskSize - 1;
    int lowerBound = 0;

    sortRequests(requests, n);

    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            currentIndex = i;
            break;
        }
    }

    printf("Head movement sequence: ");
    for (i = currentIndex; i < n; i++) {
        printf("%d ", requests[i]);
        totalSeekTime += abs(head - requests[i]);
        head = requests[i];
    }

    if (requests[0] != lowerBound) {
        printf("%d ", lowerBound);
        totalSeekTime += abs(head - lowerBound);
        head = lowerBound;
    }

