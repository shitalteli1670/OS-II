#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n) 
{
    int temp, i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() 
{
    int n, head, i, j, total_movement = 0, index;
    char direction[10];
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int request[n];
    printf("Enter disk request sequence: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &request[i]);
    }
    printf("Enter current head position: ");
    scanf("%d", &head);
    printf("Enter direction (left/right): ");
    scanf("%s", direction);
    sort(request, n);
    for (i = 0; i < n; i++) 
    {
        if (request[i] >= head) 
        {
            index = i;
            break;
        }
    }
    printf("\nOrder of disk access:\n");
    if (direction[0] == 'r' || direction[0] == 'R') 
    {
        for (j = index; j < n; j++) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
        for (j = index - 1; j >= 0; j--) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
    } 
    else 
    {
        for (j = index - 1; j >= 0; j--) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
        for (j = index; j < n; j++) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
    }
    printf("\n\nTotal head movement: %d cylinders\n", total_movement);
    return 0;
}


/*  Enter number of disk requests: 8
Enter disk request sequence: 176 79 34 60 92 11 41 114
Enter current head position: 65
Enter direction (left/right): right

Order of disk access:
 -> 79 -> 92 -> 114 -> 176 -> 60 -> 41 -> 34 -> 11

Total head movement: 276 cylinders  */