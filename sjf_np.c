
#include <stdio.h>

struct process{
    int pid;
    int at, bt;
    int wt, tat;
    int fin;
};

void sort(struct process p1[], int n){
    struct process tmp;
    for(int i=0; i<n-1; i+=1){
        for(int j=0; j<n-1; j+=1){
            if(p1[j].at > p1[j+1].at){
                tmp = p1[j];
                p1[j] = p1[j+1];
                p1[j+1] = tmp;
            }
        }
    }
}

int max(int x, int y){
    if(x<y){
        return(y);
    }
    else{
        return(x);
    }
}

int main(void){
    int n, timer = 0, min_job, idx=0, ct;
    float avgwt=0;
    float avgtat=0;
    printf("Input no. of processes: ");
    scanf("%d", &n);
    ct = n;
    int gantt[n][3];
    struct process p_array[n];
    for(int i=0; i<n; i+=1){
        p_array[i].pid = i+1;
        printf("\nProcess #%d", i+1);
        printf("\nArrival time: ");
        scanf("%d", &p_array[i].at);
        printf("Burst time: ");
        scanf("%d", &p_array[i].bt);
        p_array[i].wt = 0;
        p_array[i].tat = 0;
        p_array[i].fin = 0;
    }
    sort(p_array, n);
    printf("\nGantt chart\n");
    printf("%d",p_array[0].at);

    while(ct>0){
        min_job = 1000000;
        for(int i=0; i<n; i+=1){
            if((p_array[i].fin==0) && (p_array[1].at <=timer) && (p_array[i].bt < min_job)){
                min_job=p_array[i].bt;
                idx=i;
            }
        }
        timer = max(p_array[idx].at, timer);
        timer+=p_array[idx].bt;
        p_array[idx].fin=1;
        p_array[idx].tat = timer - p_array[idx].at;
        p_array[idx].wt = p_array[idx].tat - p_array[idx].bt;
        printf(" ->P%d <- %d",p_array[idx].pid,timer);

        ct-=1;
    }

    printf("\nProcess no. | Arrival time | Burst time | Waiting time | Turn-around time\n");
    for(int i=0;i<n;i++)
    {
        avgwt+=p_array[i].wt;
        avgtat+=p_array[i].tat;
        printf("%d\t        %d \t       %d   \t     %d \t       %d\n", p_array[i].pid, p_array[i].at, p_array[i].bt, p_array[i].wt, p_array[i].tat);

    }
    printf("Avg wt= %.2f\n",avgwt/n);
    printf("Avg tat= %.2f\n",avgtat/n);

}