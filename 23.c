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

void scan(int requests[], int n, int head, char direction) {
    int totalSeekTime = 0;
    int currentIndex, i, startPos, endPos;
    int upperBound = 199; // Upper bound of the disk cylinder
    int lowerBound = 0;   // Lower bound of the disk cylinder

    sortRequests(requests, n);

    if (direction == 'l') {
        startPos = lowerBound;
        endPos = upperBound;
    } else {
        startPos = upperBound;
        endPos = lowerBound;
    }

    if (direction == 'l') {
        for (i = 0; i < n; i++) {
            if (requests[i] >= head) {
                currentIndex = i;
                break;
            }
        }
    } else {
        for (i = n - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                currentIndex = i;
                break;
            }
        }
    }

    printf("Head movement sequence: ");
    for (i = currentIndex; i < n && i >= 0; direction == 'l' ? i++ : i--) {
        printf("%d ", requests[i]);
        totalSeekTime += abs(head - requests[i]);
        head = requests[i];
    }

    if (direction == 'l')
        printf("%d ", lowerBound);
    else
        printf("%d ", upperBound);

    totalSeekTime += abs(head - endPos);
    head = endPos;

    for (i = currentIndex - 1; i >= 0 && i < n; direction == 'l' ? i-- : i++) {
        printf("%d ", requests[i]);
        totalSeekTime += abs(head - requests[i]);
        head = requests[i];
    }

    printf("\nTotal seek time: %d\n", totalSeekTime);
}

int main() {
    int requests[MAX_REQUESTS];
    int n, head;
    char direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    printf("Enter the direction (l for left, r for right): ");
    scanf(" %c", &direction);

    if (direction != 'l' && direction != 'r') {
        printf("Invalid direction.\n");
        return 1;
    }

    scan(requests, n, head, direction);

    return 0;
}
