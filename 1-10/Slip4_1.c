#include <stdio.h>

#define P 5 
#define R 3  
int Allocation[P][R]; 
int Max[P][R];        
int Available[R];    
int Need[P][R];   
void calculateNeed() 
{
    for (int i = 0; i < P; i++) 
    {
        for (int j = 0; j < R; j++) 
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}
void displayMatrix(int matrix[P][R], const char* name) 
{
    printf("\n%s Matrix:\n", name);
    printf("   A B C\n");
    for (int i = 0; i < P; i++) 
    {
        printf("P%d ", i);
        for (int j = 0; j < R; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void displayAvailable() 
{
    printf("\nAvailable Resources:\nA B C\n");
    for (int i = 0; i < R; i++) {
        printf("%d ", Available[i]);
    }
    printf("\n");
}
void acceptValues() 
{
    printf("Enter Allocation Matrix (P x R):\n");
    for (int i = 0; i < P; i++) 
    {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) 
        {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Max Matrix (P x R):\n");
    for (int i = 0; i < P; i++) 
    {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) 
        {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("Enter Available Resources (A B C): ");
    for (int i = 0; i < R; i++) 
    {
        scanf("%d", &Available[i]);
    }
}
int main() 
{
    int choice;

    do {
        printf("\n===== Banker's Algorithm Menu =====\n");
        printf("1. Accept Allocation, Max, Available\n");
        printf("2. Display Allocation & Max matrices\n");
        printf("3. Compute and display Need matrix\n");
        printf("4. Display Available resources\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                acceptValues();
                break;

            case 2:
                displayMatrix(Allocation, "Allocation");
                displayMatrix(Max, "Max");
                break;

            case 3:
                calculateNeed();
                displayMatrix(Need, "Need");
                break;

            case 4:
                displayAvailable();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }

    } while (choice != 5);

    return 0;
}
