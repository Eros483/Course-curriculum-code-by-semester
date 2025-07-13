#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int id;
    int waitingTime;
    int burstTime;
    int turnAroundTime;
    int remainingTime;
    int completionTime;
    int arrivalTime;
    int CPUFirstTime;
    int responseTime;
    int FirstTimeFlag;
    int priority;
}Process;

int main(){
    printf("THIS IS PREEMPTIVE PRIORITY SCHEDULING ALGORITHM\n");
    printf("highest priority value has highest priority\n");
    
    int n, b; //number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes=(Process*)malloc(n*sizeof(Process));

    for (int i=0; i<n; i++){
        processes[i].id=i+1;
        printf("Enter the arrival time of process %d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time of process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority of process %d: ", i);
        scanf("%d", &processes[i].priority);
        processes[i].remainingTime=processes[i].burstTime;
        processes[i].FirstTimeFlag=-1;
    }

    int completed=0, time=0;
    int totalWaitingTime=0, totalTurnAroundTime=0, totalResponseTime=0;

    while(completed!=n){
        int minIndex=-1;
        int currentLowestPriority=-1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                if (processes[i].priority > currentLowestPriority) {
                    currentLowestPriority = processes[i].priority;
                    minIndex = i;
                }
            }
        }

        if (minIndex==INT_MAX){
            printf("CPU is idle at time %d\n", time); //idle time potential (in case process hasn't arrived)
            time++;
            continue;
        }
        else{
            printf("Process %d will run now at time %d\n", processes[minIndex].id, time);
        }
        
        if (processes[minIndex].FirstTimeFlag==-1){
            processes[minIndex].CPUFirstTime=time;
            processes[minIndex].FirstTimeFlag=1;
        }

        processes[minIndex].remainingTime--;
        time++;

        if (processes[minIndex].remainingTime==0){
            completed++;
            processes[minIndex].completionTime=time;
            processes[minIndex].turnAroundTime=processes[minIndex].completionTime-processes[minIndex].arrivalTime;
            processes[minIndex].waitingTime=processes[minIndex].turnAroundTime-processes[minIndex].burstTime;
            processes[minIndex].responseTime=processes[minIndex].CPUFirstTime-processes[minIndex].arrivalTime;

            totalResponseTime+=processes[minIndex].responseTime;
            totalWaitingTime+=processes[minIndex].waitingTime;
            totalTurnAroundTime+=processes[minIndex].turnAroundTime;
        }
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnAroundTime / n;
    float averageResponseTime = (float)totalResponseTime/n;

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].id, 
            processes[i].arrivalTime, 
            processes[i].burstTime, 
            processes[i].priority, 
            processes[i].turnAroundTime, 
            processes[i].waitingTime, 
            processes[i].responseTime
        );
    }
    

    printf("The average Turnaround Time is: %.2f\nThe average waiting time is: %.2f\nThe average response time is: %.2f\n", averageTurnaroundTime, averageWaitingTime, averageResponseTime);
    free(processes);
    return 0;  
}

/*INSTRUCTIONS TO RUN CODE
1. navigate to directory the program is stored in
2. run "gcc Assgn3SrcQ6-ArnabMandal.c"
3. run "./a.out"
*/