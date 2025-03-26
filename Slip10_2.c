#include <stdio.h>
#include <stdlib.h>

void C_SCAN(int RQ[], int n, int initial, int size, int move) {
    int TotalHeadMovement = 0;
    int i, j, index;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    printf("\nOrder of request servicing: ");

    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d ", RQ[i]);
            TotalHeadMovement += abs(initial - RQ[i]);
            initial = RQ[i];
        }

        printf("%d ", size - 1);
        TotalHeadMovement += abs(initial - (size - 1));
        initial = size - 1;

        printf("0 ");
        TotalHeadMovement += abs(initial - 0);
        initial = 0;

        for (i = 0; i < index; i++) {
            printf("%d ", RQ[i]);
            TotalHeadMovement += abs(initial - RQ[i]);
            initial = RQ[i];
        }
    } else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d ", RQ[i]);
            TotalHeadMovement += abs(initial - RQ[i]);
            initial = RQ[i];
        }

        printf("0 ");
        TotalHeadMovement += abs(initial - 0);
        initial = 0;

        printf("%d ", size - 1);
        TotalHeadMovement += abs(initial - (size - 1));
        initial = size - 1;

        for (i = n - 1; i >= index; i--) {
            printf("%d ", RQ[i]);
            TotalHeadMovement += abs(initial - RQ[i]);
            initial = RQ[i];
        }
    }

    printf("\nTotal head movement: %d\n", TotalHeadMovement);
}

int main() {
    int n, initial, size, move;
    int RQ[100];

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter the head movement direction (0 for Left, 1 for Right): ");
    scanf("%d", &move);

    C_SCAN(RQ, n, initial, size, move);

    return 0;
}

/* Enter the number of requests: 8
Enter the request sequence: 33 99 142 52 192 79 46 65
Enter initial head position: 72
Enter total disk size: 200
Enter the head movement direction (0 for Left, 1 for Right): 0

Order of request servicing: 65 52 46 33 0 199 192 142 99 79 
Total head movement: 391
 */
