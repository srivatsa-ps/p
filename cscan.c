#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    int RQ[]= {356,544,1212,1523,1618,2069,2296,2800,3681,4965};
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    // logic for C-Scan disk scheduling
    printf("\nseek sequence\n");
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
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
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
        for(i=index;i<n;i++)
        {
            printf("%d ",initial);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        printf("%d ",initial);
        //  last movement for max size 
        printf("%d ",size);
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        /*movement max to min disk */
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
        for( i=0;i<index;i++)
        {
             printf("%d ",initial);
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
        printf("%d ",initial);

    printf("\nTotal head movement is %d\n",TotalHeadMoment);
    return 0;
}