#include <stdio.h>

void calculateNeed(int need[10][10], int max[10][10], int alloc[10][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

int isSafe(int alloc[10][10], int max[10][10], int avail[10], int m, int n) {
    int need[10][10];
    calculateNeed(need, max, alloc, m, n);
    
    int finish[10] = {0};
    int safeSeq[10];
    int work[10];
    for (int i = 0; i < n; i++)
        work[i] = avail[i];
    
    int count = 0;
    while (count < m) {
        int found = 0;
        for (int i = 0; i < m; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < n; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == n) {
                    for (int k = 0; k < n; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }
    printf("The system is in a safe state. Safe sequence is: ");
    for (int i = 0; i < m; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return 1;
}

int main() {
    int m, n;
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resource types: ");
    scanf("%d", &n);

    int alloc[10][10], max[10][10], avail[10];
    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &avail[i]);
    
    isSafe(alloc, max, avail, m, n);
    return 0;
}

/*
Enter the number of processes: 5
Enter the number of resource types: 4
Enter Allocation matrix:
0 0 1 2 
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Enter Maximum matrix:
0 0 1 2 
0 7 5 0 
2 3 5 6 
0 6 5 2
0 6 5 6
Enter Available resources:
1 5 2 0
The system is in a safe state. Safe sequence is: P0 P2 P3 P4 P1 
*/