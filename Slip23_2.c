#include <stdio.h>
#include <stdlib.h>

void SSTF(int RQ[], int n, int initial) 
{
    int TotalHeadMovement = 0, count = 0;
    int completed[n];
    for (int i = 0; i < n; i++)
        completed[i] = 0;
    printf("\nSequence of request execution: %d", initial);
    while (count < n) 
	{
        int min = 10000, index = -1;
        for (int i = 0; i < n; i++) 
		{
            if (!completed[i]) 
			{ 
                int distance = abs(RQ[i] - initial);
                if (distance < min) 
				{
                    min = distance;
                    index = i;
                }
            }
        }
        if (index == -1) break; 
        TotalHeadMovement += min;
        initial = RQ[index];
        completed[index] = 1;
        count++;
        printf(" -> %d", initial);
    }
    printf("\nTotal head movement: %d\n", TotalHeadMovement);
}
int main() 
{
    int n, initial;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int RQ[n];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &initial);
    SSTF(RQ, n, initial);
    return 0;
}

/* Enter the number of requests: 8
Enter the request sequence: 24 90 133 43 188 70 37 55
Enter the initial head position: 58

Sequence of request execution: 58 -> 55 -> 43 -> 37 -> 24 -> 70 -> 90 -> 133 -> 188
Total head movement: 198  */
