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
    int CPUFirstTime;//increased variables to calculate response time, as significant variable
    int responseTime;
    int FirstTimeFlag;
}Process;

int main(){
    printf("THIS IS SRTF SCHEDULING ALGORITHM\n");
    
    int n, b; //number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n<=0){
        printf("Invalid number of processes\n");
        return 1;
    }

    Process *processes=(Process*)malloc(n*sizeof(Process));

    for (int i=0; i<n; i++){
        processes[i].id=i+1;
        printf("Enter the arrival time of process %d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        if (processes[i].arrivalTime<0){
            printf("Invalid arrival time\n");
            return 1;
        }
        printf("Enter burst time of process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        if (processes[i].burstTime<=0){
            printf("Invalid burst time\n");
            return 1;
        }
        processes[i].remainingTime=processes[i].burstTime;
        processes[i].FirstTimeFlag=-1;
    }

    int completed=0, time=0, minIndex;
    int totalWaitingTime=0, totalTurnAroundTime=0, totalResponseTime=0;

    while(completed!=n){
        minIndex=-1;
        int minRemainingTime=INT_MAX;

        //finding shortest remaining time
        for (int i=0; i<n; i++){
            if (processes[i].arrivalTime<=time){
                if (processes[i].remainingTime>0 && processes[i].remainingTime<minRemainingTime){
                    minRemainingTime=processes[i].remainingTime;
                    minIndex=i;
                }
            }
        }

        if (minIndex==-1){
            time++;
            printf("CPU is idle at time %d\n", time); //idle time potential (in case process hasn't arrived)
            continue;
        }
        else{
            printf("Process %d will run now at time %d\n", minIndex+1, time);
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

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].turnAroundTime, processes[i].waitingTime, processes[i].responseTime);
    }
    

    printf("The average Turnaround Time is: %.2f\nThe average waiting time is: %.2f\nThe average response time is: %.2f\n", averageTurnaroundTime, averageWaitingTime, averageResponseTime);
    free(processes);
    return 0;  
}

/*INSTRUCTIONS TO RUN CODE
1. navigate to directory the program is stored in
2. run "gcc Assgn3SrcQ3-ArnabMandal.c"
3. run "./a.out"
*/