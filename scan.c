#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    int RQ[]= {2069,1212,356,1523,3681,2296,544,1618,4965,2800};
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);

    printf("\nseek sequence\n");

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

    int index,ind;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            ind= i-1;
            index=i;
            break;
        }
    }
   

        for(i=index;i<n;i++)
        {
            printf("%d ",initial);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        printf("%d ",initial);

        printf("%d ",size);
        TotalHeadMoment=TotalHeadMoment+abs(size-initial);

        initial= RQ[ind];
        TotalHeadMoment=TotalHeadMoment+abs(size-initial);
        for( i=ind-1;i>=0;i--)
        {
             printf("%d ",initial);
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             //printf("%d\n",abs(RQ[i]-initial));
             initial=RQ[i];
        }
        printf("%d ",initial);
    
    printf("\nTotal head movement is %d\n",TotalHeadMoment);
    return 0;
}