#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()

{

    int pas,las,ps,fs,np,nf,allocation[15], pgtable[15];
    int y,r, i,j,ne,k=0,sa[15],k1,la,pageno,offset,pa,q=0,temp,x,add;
    int c;
    time_t t;

    //pas= paging address space, las=logical address space

    printf("\n Enter the size of physical address space:");
    scanf("%d",&pas);
    printf("\n Enter the size of logical address space:");
    scanf("%d",&las);
    printf("\n Enter the size of each page ");
    scanf("%d",&ps);

    // framesize = pagesize
    fs=ps;  
    //no: of pages= logical address space/page size               
    np=las/ps;
    //no: of frames= physical address space/frame size
    nf=pas/fs;

    //initializing all allocations to -1
   for(i=0;i<nf;i++)
      allocation[i]=-1;

    //starting address set 4000
   sa[q]=4000;

   for(y=0;y<nf;y++)
    {  temp=sa[q]+ps;
       sa[++q]=temp;
    }

    //printing page-map table before allocation
    printf("\n Before allocation:");
    printf("\n Frame number\tPage number\tstarting address");
    for(k1=0;k1<nf;k1++)
    {
    printf("\n%d\t\t%d\t\t%d",k1,allocation[k1],sa[k1]);
    }

    //random mapping of frameno: to pageno:
    srand((unsigned) time(&t));
    for(j=0;j<np;j++)
    {
        r=rand()%nf;
        while(allocation[r]!=-1)
        {
            r=rand()%nf;
        }
        allocation[r]=k; //pagenos: mapped to random framenos:
        k++;
        pgtable[j]=r;
    }
    
    //After allocation
    printf("'\n After allocation:");
    printf( "\nFrame number\tPage number\tstarting address");
    for(k=0;k<nf;k++)
    printf("\n %d\t\t%d\t\t%d",k,allocation[k],sa[k]);


    printf("\n Enter the logical address");
    scanf("%d" ,&la);
    if(la>las)
    {
    printf ("Trap: Invalid logical address");
    exit(0);
    }

    pageno=la/np;
    for(x=0;x<nf;x++)
    {
        if(allocation[x]==pageno)
        {
            printf("%d",x);
            add=sa[x]; //address of the corres. pageno:
        }
    }
    ne=las/ps;
    offset=la%ne;
    printf("\n Offset address: %d",offset);
    pa=offset+add;
    printf("\n Physical address: %d\n",pa);
    return 0;

    }