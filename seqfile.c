#include <stdio.h>
#include <stdlib.h>


typedef struct File{
    char name[100];
    int start;
    int length;
}File;


int main()
{
    int disk_size;
    printf("Enter the number of blocks in disk :");
    scanf(" %d",&disk_size);
    int disk[disk_size];
    for(int i=0;i<disk_size;i++)
    {
        disk[i] = -1;
    }
    File files[100];
    char choice ='y';
    int i = -1;
    while(choice!='n')
    {
       if(i==-1)
       {
        printf("Add files to disk..");
       }
       else
       {
        printf("\nFiles in disk..");
        printf("\nFileName StartBlock EndBlock\n");
        for(int j=0;j<i+1;j++)
        {
            printf("%s\t%d\t%d\n",files[j].name,files[j].start,files[j].length);
        }
       }
       printf("\n");
       char name[100];
       int start,length,flag = 0;
       printf("Enter name of file , start and length of file : ");
       scanf(" %s",name);
       scanf(" %d",&start);
       scanf(" %d",&length);
       for(int j=start;j<start+length;j++)
       {
            if(disk[j]!=-1)
                flag = 1;
       }
       if(flag == 1)
       {
        printf("\nFile cannot be allocated...");
        printf("\nDo you want to continue y/n :");
        scanf(" %c",&choice);
        continue;
       }
       printf("\nFile is being allocated..");
       i++;
       for(int j=0;name[j]!='\0';j++)
        files[i].name[j] = name[j];
       files[i].start = start;
       files[i].length = length;
       for(int j=start;j<start+length;j++)
        {
            disk[j] = 1;
        }
        printf("\nFile has been sucessfully allocated!!");
        printf("\nDo you want to continue y/n :");
        scanf(" %c",&choice);
    }
    return 0;
}