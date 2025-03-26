#include <stdio.h>
#include <stdlib.h>

void SCAN(int arr[], int n, int head, int size, int direction) {
    int total_movement = 0;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int index = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] > head) {
            index = i;
            break;
        }
    }

    printf("\nDisk Scheduling Order:\n");
    if (direction == 0) {
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", arr[i]);
            total_movement += abs(arr[i] - head);
            head = arr[i];
        }
        printf("0 -> ");
        total_movement += abs(head - 0);
        head = 0;
        for (i = index; i < n; i++) {
            printf("%d -> ", arr[i]);
            total_movement += abs(arr[i] - head);
            head = arr[i];
        }
    } 
    else {
        for (i = index; i < n; i++) {
            printf("%d -> ", arr[i]);
            total_movement += abs(arr[i] - head);
            head = arr[i];
        }
        printf("%d -> ", size - 1);
        total_movement += abs(head - (size - 1));
        head = size - 1;
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", arr[i]);
            total_movement += abs(arr[i] - head);
            head = arr[i];
        }
    }

    printf("End\n");
    printf("Total Head Movement: %d\n", total_movement);
}

int main() {
    int n, head, size, direction;

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter disk request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter head movement direction (0 for Left, 1 for Right): ");
    scanf("%d", &direction);

    SCAN(arr, n, head, size, direction);

    return 0;
}

/*
Enter total disk size: 200
Enter number of disk requests: 8
Enter disk request sequence:
86 147 91 170 95 130 102 70
Enter initial head position: 125
Enter head movement direction (0 for Left, 1 for Right): 0

Disk Scheduling Order:
102 -> 95 -> 91 -> 86 -> 70 -> 0 -> 130 -> 147 -> 170 -> End
Total Head Movement: 295
*/
