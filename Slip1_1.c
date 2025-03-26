/* Q.1 ) Write a C Menu driven Program to implement following functionality
a) Accept Available
b) Display Allocation, Max
c) Display the contents of need matrix
d) Display Available */

#include <stdio.h>
int N, M, Available[10], tempAvailable[10], Max[10][10], Alloc[10][10], Need[10][10], safeseq[10];
void AcceptInput()
{
    int i, j;
    printf("\nEnter The Number Of Processes: ");
    scanf("%d", &N);
    printf("\nEnter The Number Of Resource Types: ");
    scanf("%d", &M);
    printf("\nEnter Available: ");
    for (i = 0; i < M; i++)
    {
        scanf("%d", &Available[i]);
        tempAvailable[i] = Available[i];
    }
    printf("\nEnter Max: ");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &Max[i][j]);
        }
    }
    printf("\nEnter Allocation: ");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &Alloc[i][j]);
        }
    }

    for (i = 0; i < N; i++)
        safeseq[i] = -1;
}
void DisplayMatrix(int a[10][10], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}
void CalNeed()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            Need[i][j] = Max[i][j] - Alloc[i][j];
        }
    }
}
int IsFeasible(int Pno)
{
    int i;
    for (i = 0; i < M; i++)
    {
        if (Need[Pno][i] > Available[i])
            return 0;
    }
    return 1;
}
void Banker()
{
    int k = 0, i, j, flags[10] = {0}, finish = 0;

    while (finish != 1)
    {
        int allocated = 0;
        for (i = 0; i < N; i++)
        {
            if (IsFeasible(i) && flags[i] != 1)
            {
                for (j = 0; j < M; j++)
                {
                    Available[j] += Alloc[i][j];
                }
                safeseq[k++] = i;
                flags[i] = 1;
                allocated = 1;
            }
        }
        if (!allocated)
            break;
        finish = 1;
        for (i = 0; i < N; i++)
        {
            if (flags[i] == 0)
            {
                finish = 0;
                break;
            }
        }
    }
}
void PrintSafeSeq()
{
    int i;
    printf("\nSafe Sequence: ");
    printf("<");
    for (i = 0; i < N; i++)
        printf("P%d->", safeseq[i]);
    printf("\b>\n");
}
void NewRequest()
{
    int i;
    int NewReq[10];
    printf("\nEnter New Request for each resource:");
    for (i = 0; i < M; i++)
    {
        printf("\n Enter %c: ", 'A' + i);
        scanf("%d", &NewReq[i]);
    }
    for (i = 0; i < M; i++)
    {
        if (NewReq[i] > tempAvailable[i])
        {
            printf("\nNot feasible, resource cannot be granted\n");
            return;
        }
    }
    printf("\nFeasible, resource can be granted\n");
}
int main()
{
    AcceptInput();
    CalNeed();
    printf("\nMAX:\n");
    DisplayMatrix(Max, N, M);
    printf("\nALLOCATION:\n");
    DisplayMatrix(Alloc, N, M);
    printf("\nNEED:\n");
    DisplayMatrix(Need, N, M);
    Banker();
    PrintSafeSeq();
    NewRequest();
    return 0;
}
