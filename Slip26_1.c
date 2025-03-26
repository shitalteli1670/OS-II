#include <stdio.h>

#define P 5 
#define R 4 

int Available[R], tempAvailable[R];
int Max[P][R], Alloc[P][R], Need[P][R], safeseq[P];
void AcceptInput() {
    int i, j;
    printf("\nEnter Available Resources (A, B, C, D): ");
    for (i = 0; i < R; i++) {
        scanf("%d", &Available[i]);
        tempAvailable[i] = Available[i];
    }

    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++)
            scanf("%d", &Max[i][j]);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++)
            scanf("%d", &Alloc[i][j]);

    for (i = 0; i < P; i++)
        safeseq[i] = -1;
}
void DisplayMatrix(int matrix[P][R], const char* name) {
    printf("\n%s Matrix:\n", name);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++)
            printf("%5d", matrix[i][j]);
        printf("\n");
    }
}
void CalNeed() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            Need[i][j] = Max[i][j] - Alloc[i][j];
}
int IsFeasible(int Pno) {
    for (int i = 0; i < R; i++) {
        if (Need[Pno][i] > Available[i])
            return 0;
    }
    return 1;
}
int Banker() {
    int k = 0, i, j, flags[P] = {0}, finish = 0;

    while (finish != 1) {
        int allocated = 0;
        for (i = 0; i < P; i++) {
            if (IsFeasible(i) && flags[i] == 0) {
                for (j = 0; j < R; j++)
                    Available[j] += Alloc[i][j];

                safeseq[k++] = i;
                flags[i] = 1;
                allocated = 1;
            }
        }

        if (!allocated) {
            printf("\nSystem is in an UNSAFE state! Deadlock may occur.\n");
            return 0;
        }

        finish = 1;
        for (i = 0; i < P; i++)
            if (flags[i] == 0)
                finish = 0;
    }

    return 1;
}
void PrintSafeSeq() {
    printf("\nSafe Sequence: < ");
    for (int i = 0; i < P; i++)
        printf("P%d%s", safeseq[i], (i == P - 1) ? " " : " -> ");
    printf(">\n");
}
void NewRequest() {
    int i, j, NewReq[R];

    printf("\nEnter New Request for resources (A, B, C, D): ");
    for (i = 0; i < R; i++)
        scanf("%d", &NewReq[i]);
    for (i = 0; i < R; i++) {
        if (NewReq[i] > tempAvailable[i]) {
            printf("\nNot feasible, resource cannot be granted.\n");
            return;
        }
    }
    for (i = 0; i < R; i++) {
        tempAvailable[i] -= NewReq[i];
        Alloc[0][i] += NewReq[i]; 
        Need[0][i] -= NewReq[i];
    }
    printf("\nChecking system state after request...\n");
    if (Banker()) {
        printf("\nRequest granted safely!\n");
    } else {
        printf("\nRequest cannot be granted safely. Rolling back...\n");
        for (i = 0; i < R; i++) {
            tempAvailable[i] += NewReq[i];
            Alloc[0][i] -= NewReq[i];
            Need[0][i] += NewReq[i];
        }
    }
}
int main() 
{
    AcceptInput();
    CalNeed();

    printf("\nMAX:");
    DisplayMatrix(Max, "MAX");

    printf("\nALLOCATION:");
    DisplayMatrix(Alloc, "ALLOCATION");

    printf("\nNEED:");
    DisplayMatrix(Need, "NEED");

    if (Banker()) {
        PrintSafeSeq();
    }

    NewRequest();
    return 0;
}


/* Enter Available Resources (A, B, C, D): 1 5 2 0

Enter Max Matrix:
0 0 1 2 
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6

Enter Allocation Matrix:
0 0 1 2       
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4

MAX:
MAX Matrix:
    0    0    1    2
    1    7    5    0
    2    3    5    6
    0    6    5    2
    0    6    5    6

ALLOCATION:
ALLOCATION Matrix:
    0    0    1    2
    1    0    0    0
    1    3    5    4
    0    6    3    2
    0    0    1    4

NEED:
NEED Matrix:
    0    0    0    0
    0    7    5    0
    1    0    0    2
    0    0    2    0
    0    6    4    2

Safe Sequence: < P0 -> P2 -> P3 -> P4 -> P1 >

Enter New Request for resources (A, B, C, D): 1 2 1 0

Checking system state after request...

Request granted safely! */