#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,TotalHeadMoment=0,initial,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    int RQ[]= {2069,1212,356,1523,3681,2296,544,1618,4965,2800};
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    
    printf("\nseek sequence\n");
    // logic for sstf disk scheduling
    
        /* loop will execute until all process is completed*/
    while(count!=n)
    {
        int min=99999,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-initial);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        printf("%d ",RQ[index]);
        TotalHeadMoment=TotalHeadMoment+min;
        initial=RQ[index];
        // 1000 is for max
        // you can use any number
        RQ[index]=99999;
        count++;
    }
    
    printf("\nTotal head movement is %d\n",TotalHeadMoment);
    return 0;
}