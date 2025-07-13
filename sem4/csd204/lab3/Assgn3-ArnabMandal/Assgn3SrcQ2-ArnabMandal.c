#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int waitingTime;
    int burstTime;
    int turnAroundTime;
}Process;

void sortByBurstTime(Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                //swapping processes as per burst time
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main(){
    printf("THIS IS SHORTEST JOB FIRST NON-PREEMPTIVE SCHEDULING ALGORITHM\n");
    
    int n, b; //number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n<=0){
        printf("Invalid number of processes\n");
        return 1;
    }

    Process *processes=(Process*)malloc(n*sizeof(Process));

    for (int i=0; i<n; i++){
        printf("Enter the id of process %d: ", i);
        scanf("%d", &processes[i].id);
        printf("Enter burst time of process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        if (processes[i].burstTime<=0){
            printf("Invalid burst time\n");
            return 1;
        }
    }

    sortByBurstTime(processes, n);

    processes[0].waitingTime=0;
    processes[0].turnAroundTime=processes[0].burstTime;

    for (int i=1; i<n; i++){
        processes[i].waitingTime=processes[i-1].waitingTime+processes[i-1].burstTime;
        processes[i].turnAroundTime=processes[i].waitingTime+processes[i].burstTime;
    }

    long long totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i=0; i<n;i++){
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime+=processes[i].turnAroundTime;
    }
    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnAroundTime / n;

    printf("The average Turnaround Time is: %.2f\nThe average waiting time is: %.2f\n", averageTurnaroundTime, averageWaitingTime);
    free(processes);
    return 0;  
}

/*INSTRUCTIONS TO RUN CODE
1. navigate to directory the program is stored in
2. run "gcc Assgn3SrcQ2-ArnabMandal.c"
3. run "./a.out"
*/