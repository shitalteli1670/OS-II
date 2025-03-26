#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, head, item[20], dst[20], direction;
    int cylinders = 0;

    printf("Enter number of locations: ");
    scanf("%d", &n);

    printf("Enter position of head: ");
    scanf("%d", &head);

    printf("Enter elements of disk queue: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &item[i]);
        dst[i] = (head - item[i]);
    }

    printf("Enter head movement direction (Right=1, Left=0): ");
    scanf("%d", &direction);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(item[j] < item[i])
            {
                int temp = item[j];
                item[j] = item[i];
                item[i] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(item[i] >= head)
        {
            j = i;
            break;
        }
    }

    printf("\nOrder of disk allocation is as follows:\n");
    
    if(direction == 1) // Moving Right
    {
        for(i = j; i < n; i++)
        {
            printf("-> %d ", item[i]);
            cylinders += abs(head - item[i]);
            head = item[i];
        }
        for(i = 0; i < j; i++)
        {
            printf("-> %d ", item[i]);
            cylinders += abs(head - item[i]);
            head = item[i];
        }
    }
    else // Moving Left
    {
        for(i = j - 1; i >= 0; i--)
        {
            printf("-> %d ", item[i]);
            cylinders += abs(head - item[i]);
            head = item[i];
        }
        for(i = n - 1; i >= j; i--)
        {
            printf("-> %d ", item[i]);
            cylinders += abs(head - item[i]);
            head = item[i];
        }
    }

    printf("\n\nTotal cylinder movement: %d\n", cylinders);
    return 0;
}


 /*Enter number of locations: 8
Enter position of head: 40
Enter elements of disk queue: 23 89 132 42 187 69 36 55
Enter head movement direction (Right=1, Left=0): 1

Order of disk allocation is as follows:
-> 42 -> 55 -> 69 -> 89 -> 132 -> 187 -> 23 -> 36 

Total cylinder movement: 324
*/