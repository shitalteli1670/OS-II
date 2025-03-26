#include <stdio.h>

#define P 5 
#define R 3 

int Available[R], tempAvailable[R];
int Max[P][R], Alloc[P][R], Need[P][R], safeseq[P];

void AcceptInput() {
    int i, j;
    printf("\nEnter Available Resources (A, B, C): ");
    for (i = 0; i < R; i++) {
        scanf("%d", &Available[i]);
        tempAvailable[i] = Available[i];  // Store original available resources
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
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            Need[i][j] = Max[i][j] - Alloc[i][j];
            if (Need[i][j] < 0) {
                printf("\nError: Allocation cannot be greater than Max for P%d in resource %c.\n", i, 'A' + j);
                return;
            }
        }
    }
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
    int Work[R];  // Temporary available resources for processing

    // Copy Available resources to Work array
    for (i = 0; i < R; i++) {
        Work[i] = Available[i];
    }

    while (finish != 1) {
        int allocated = 0;
        for (i = 0; i < P; i++) {
            if (IsFeasible(i) && flags[i] == 0) {
                for (j = 0; j < R; j++)
                    Work[j] += Alloc[i][j];

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

    printf("\nEnter New Request for resources (A, B, C): ");
    for (i = 0; i < R; i++)
        scanf("%d", &NewReq[i]);

    // Check if the request is greater than available resources
    for (i = 0; i < R; i++) {
        if (NewReq[i] > tempAvailable[i]) {
            printf("\nNot feasible, resource cannot be granted.\n");
            return;
        }
    }

    // Simulate resource allocation temporarily
    int tempAlloc[R], tempNeed[R], tempAvail[R];
    for (i = 0; i < R; i++) {
        tempAlloc[i] = Alloc[0][i] + NewReq[i];
        tempNeed[i] = Need[0][i] - NewReq[i];
        tempAvail[i] = tempAvailable[i] - NewReq[i];
    }

    printf("\nChecking system state after request...\n");

    // Simulate a safe state check
    int safe = 1;
    for (i = 0; i < P; i++) {
        if (tempNeed[i] > tempAvail[i]) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("\nRequest granted safely!\n");

        // Apply actual changes if system is safe
        for (i = 0; i < R; i++) {
            tempAvailable[i] -= NewReq[i];
            Alloc[0][i] += NewReq[i];
            Need[0][i] -= NewReq[i];
        }
    } else {
        printf("\nRequest cannot be granted safely. Rolling back...\n");
    }
}

int main() {
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
