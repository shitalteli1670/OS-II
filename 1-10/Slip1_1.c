#include <stdio.h>
#define PROCESS_COUNT 5
#define RESOURCE_COUNT 3
int available[RESOURCE_COUNT];
int allocation[PROCESS_COUNT][RESOURCE_COUNT] = {
    {2, 3, 2},
    {4, 0, 0},
    {5, 0, 4},
    {4, 3, 3},
    {2, 2, 4}
};
int max[PROCESS_COUNT][RESOURCE_COUNT] = {
    {9, 7, 5},
    {5, 2, 2},
    {1, 0, 4},
    {4, 4, 4},
    {6, 5, 5}
};
int need[PROCESS_COUNT][RESOURCE_COUNT];
void calculateNeedMatrix() {
    for (int i = 0; i < PROCESS_COUNT; i++) {
        for (int j = 0; j < RESOURCE_COUNT; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
void displayAllocationAndMax() 
{
    printf("Process\tAllocation\tMax\n");
    printf("\tA B C\t\tA B C\n");
    
    for (int i = 0; i < PROCESS_COUNT; i++) {
        printf("P%d\t", i);
        
        for (int j = 0; j < RESOURCE_COUNT; j++) {
            printf("%d ", allocation[i][j]);
        }
        
        printf("\t\t");
        
        for (int j = 0; j < RESOURCE_COUNT; j++) {
            printf("%d ", max[i][j]);
        }
        
        printf("\n");
    }
}


void displayNeedMatrix() 
{
    printf("Process\tNeed\n");
    printf("\tA B C\n");
    
    for (int i = 0; i < PROCESS_COUNT; i++) {
        printf("P%d\t", i);
        
        for (int j = 0; j < RESOURCE_COUNT; j++) {
            printf("%d ", need[i][j]);
        }
        
        printf("\n");
    }
}
void displayAvailable() 
{
    printf("Available Resources: ");
    
    for (int i = 0; i < RESOURCE_COUNT; i++) {
        printf("%d ", available[i]);
    }
    
    printf("\n");
}
void acceptAvailable() 
{
    printf("Enter available resources (A B C): ");
    
    for (int i = 0; i < RESOURCE_COUNT; i++) {
        scanf("%d", &available[i]);
    }
}

int main() {
    int choice;
    calculateNeedMatrix();
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation and Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                acceptAvailable();
                break;
            case 2:
                displayAllocationAndMax();
                break;
            case 3:
                displayNeedMatrix();
                break;
            case 4:
                displayAvailable();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    
    return 0;
}
