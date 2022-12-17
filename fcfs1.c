#include <stdio.h>

struct process{
    int pid;
    int at, bt;
    int wt, tat;
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
    int n, timer=0;
    printf("Input no. of processes: ");
    scanf("%d", &n);
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
    }

    sort(p_array, n);
    printf("\nProcess no. | Arrival time | Burst time | Waiting time | Turn-around time\n");
    for(int i=0; i<n; i+=1){
        timer = max(p_array[i].at, timer);
        timer+=p_array[i].bt;
        p_array[i].tat = timer - p_array[i].at;
        p_array[i].wt = p_array[i].tat - p_array[i].bt;
        printf("%d        %d        %d        %d        %d\n", p_array[i].pid, p_array[i].at, p_array[i].bt, p_array[i].wt, p_array[i].tat);
        gantt[i][0]= i;
        gantt[i][1] = p_array[i].at+p_array[i].wt;
        gantt[i][2] = p_array[i].bt;
    }

    printf("\nGantt chart\n===========\n");
    for(int i=0; i<n; i+=1){
        printf("P%d|", gantt[i][0]);
        for(int j=0; j<gantt[i][1]; j+=1){
            printf("-");
        }
        for(int k=0; k<gantt[i][2]; k+=1){
            printf("X");
        }
        printf("\n");
    }
}