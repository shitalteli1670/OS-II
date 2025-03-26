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
    int n, head, i, j, total_movement = 0;
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
    printf("\nOrder of disk access:\n");
    if (direction[0] == 'r' || direction[0] == 'R') 
    {
        for (i = 0; i < n; i++) 
        {
            if (request[i] >= head) 
            {
                break;
            }
        }
        for (j = i; j < n; j++) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
        for (j = 0; j < i; j++) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
    } 
    else 
    {
        for (i = n - 1; i >= 0; i--) 
        {
            if (request[i] <= head) 
            {
                break;
            }
        }
        for (j = i; j >= 0; j--) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
        for (j = n - 1; j > i; j--) 
        {
            printf(" -> %d", request[j]);
            total_movement += abs(head - request[j]);
            head = request[j];
        }
    }
    printf("\n\nTotal head movement: %d cylinders\n", total_movement);
    return 0;
}

/*  Enter number of disk requests: 9
Enter disk request sequence: 56 59 40 19 91 161 151 39 185
Enter current head position: 48
Enter direction (left/right): right

Order of disk access:
 -> 56 -> 59 -> 91 -> 151 -> 161 -> 185 -> 19 -> 39 -> 40

Total head movement: 324 cylinders  */