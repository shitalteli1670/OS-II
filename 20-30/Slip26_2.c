#include <stdio.h>
#include <stdlib.h>
int main() {
    int queue[20], n, head, i, seek = 0, diff;
    float avg;
    printf("Enter the max range of disk: \n");
    int max;
    scanf("%d", &max);
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read: \n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position: \n");
    scanf("%d", &head);
    printf("\nOrder of disk access:\n");
    printf("%d", head);
    for (i = 0; i < n; i++) 
	{
        diff = abs(queue[i] - head);
        seek += diff;
        printf(" -> %d", queue[i]);
        head = queue[i];
    }
    printf("\n\nTotal seek time is: %d\n", seek);
    avg = (float)seek / n;
    printf("Average seek time is: %.2f\n", avg);
    return 0;
}

/*  Enter the max range of disk: 
200
Enter the size of queue: 9
Enter the queue of disk positions to be read: 
56 59 40 19 91 161 151 39 185
Enter the initial head position: 
48

Order of disk access:
48 -> 56 -> 59 -> 40 -> 19 -> 91 -> 161 -> 151 -> 39 -> 185

Total seek time is: 461
Average seek time is: 51.22  */
