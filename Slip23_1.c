#include <stdio.h>
#include <stdlib.h>
void displayMatrix(int matrix[][10], int m, int n) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculateNeedMatrix(int allocation[][10], int max[][10], int need[][10], int m, int n) {
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
int canGrantRequest(int request[], int available[], int need[][10], int process_id, int n) {
    for (int i = 0; i < n; i++) 
    {
        if (request[i] > need[process_id][i]) 
        {
            return 0;
        }
        if (request[i] > available[i]) 
        {
            return 0; 
        }
    }
    return 1;
}
int main() 
{
    int m, n;
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resource types: ");
    scanf("%d", &n);
    int allocation[10][10], max[10][10], available[10], need[10][10], request[10], process_id;
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Available resources:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &available[i]);
    }
    calculateNeedMatrix(allocation, max, need, m, n);
    printf("\nNeed Matrix:\n");
    displayMatrix(need, m, n);
    printf("Enter the process number making the request (0 to %d): ", m - 1);
    scanf("%d", &process_id);
    printf("Enter the request for process P%d: ", process_id);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &request[i]);
    }
    if (canGrantRequest(request, available, need, process_id, n)) 
    {
        printf("The request can be granted immediately.\n");
    } else {
        printf("The request cannot be granted immediately.\n");
    }
    return 0;
}

/*  Enter the number of processes: 3
Enter the number of resource types: 3
Enter the Allocation Matrix:
0 1 0
2 0 0
3 0 3
Enter the Maximum Matrix:
7 5 3
3 2 2
9 0 2
Enter the Available resources:
3 3 2

Need Matrix:
7 4 3
1 2 2
6 0 -1

Enter the process number making the request (0 to 2): 1
Enter the request for process P1: 1 0 2

The request can be granted immediately.    */
