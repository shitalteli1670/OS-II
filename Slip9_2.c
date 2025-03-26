#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the requasts sequance\n");
    for(i=0; i<n; i++)
        scanf("%d",&RQ[i]);
        printf("Enter initial head position\n");
        scanf("%d",&initial);
        printf("Enter total disk size\n");
        scanf("%d",&size);
        printf("Enter the head movement direction for right 1 and for left 0\n");
        scanf("%d",&move);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-i-1; j++)
            {
                if(RQ[j]>RQ[j+1])
                {
                    int temp;
                    temp=RQ[j];
                    RQ[j]=RQ[j+1];
                    RQ[j+1]=temp;
                }
            }
        }
        int index;
        for(i=0; i<n; i++)
        {
            if(initial<RQ[i])
            {
                index=i;
                break;
            }
        }
        if(move==1)
        {
            for(i=index; i<n; i++)
            {
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
                initial=RQ[i];
            }
            for(i=index-1; i>=0; i--)
            {
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
                initial=RQ[i];
            }
        }
        else
        {
            for(i=index-1; i>=0; i--)
            {
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
                initial=RQ[i];
            }
            for(i=index; i<n; i++)
            {
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
                initial=RQ[i];
            }
        }
        printf("Total head movement is %d", TotalHeadMoment);
        return 0;
}

/*Enter the number of requests
8
Enter the requasts sequance
176 79 34 60 92 11 41 114
Enter initial head position
65
Enter total disk size
200
Enter the head movement direction for right 1 and for left 0
0
Total head movement is 219*/