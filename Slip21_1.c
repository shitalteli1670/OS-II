#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, seek = 0, max, diff;
    float avg;
    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        if (queue[i] < 0 || queue[i] >= max) {
            printf("Error: Request %d is out of disk range (0 to %d)\n", queue[i], max - 1);
            return 1;
        }
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    if (head < 0 || head >= max) {
        printf("Error: Initial head position is out of range!\n");
        return 1;
    }
    printf("\nOrder of execution:\n");
    for (i = 0; i < n; i++) {
        diff = abs(queue[i] - head);
        seek += diff;
        printf("Head moves from %d to %d with seek %d\n", head, queue[i], diff);
        head = queue[i];
    }
    printf("\nTotal seek time: %d\n", seek);
    avg = (float)seek / n;
    printf("Average seek time: %.2f\n", avg);

    return 0;
}

/* output
Enter the max range of disk: 200
Enter the size of queue: 9
Enter the queue of disk positions to be read:
55 58 39 18 90 160 150 38 184
Enter the initial head position: 50

Order of execution:
Head moves from 50 to 55 with seek 5
Head moves from 55 to 58 with seek 3
Head moves from 58 to 39 with seek 19
Head moves from 39 to 18 with seek 21
Head moves from 18 to 90 with seek 72
Head moves from 90 to 160 with seek 70
Head moves from 160 to 150 with seek 10
Head moves from 150 to 38 with seek 112
Head moves from 38 to 184 with seek 146

Total seek time: 458
Average seek time: 50.89*/
