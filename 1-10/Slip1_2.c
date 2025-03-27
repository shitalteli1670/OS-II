#include <stdio.h>
#include <stdlib.h>
void fcfs(int requests[], int n, int head) 
{
    int totalMovement = 0;

    printf("Request served in order: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", requests[i]);
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }
    printf("\nTotal head movements: %d\n", totalMovement);
}
int main() 
{
    int n, head;
    printf("Enter total number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk request string: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the starting head position: ");
    scanf("%d", &head);
    fcfs(requests, n, head);
    return 0;
}
