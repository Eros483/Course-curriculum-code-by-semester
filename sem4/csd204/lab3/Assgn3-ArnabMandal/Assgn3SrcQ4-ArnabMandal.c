#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
    int completionTime;
    int arrivalTime;
    int CPUFirstTime;
    int responseTime;
    int FirstTimeFlag;
} Process;

int main() {
    printf("THIS IS ROUND-ROBIN SCHEDULING ALGORITHM\n");

    int n, timeQuantum; //introducing quantum variable for RR
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n<=0){
        printf("Invalid number of processes\n");
        return 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    if (timeQuantum<=0){
        printf("Invalid time quantum\n");
        return 1;
    }

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        if (processes[i].arrivalTime<0){
            printf("Invalid arrival time\n");
            return 1;
        }
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);

        if (processes[i].burstTime<=0){
            printf("Invalid number of processes\n");
            return 1;
        }

        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnAroundTime = 0;
        processes[i].FirstTimeFlag = -1;
    }

    int completed = 0, time = 0, front = 0, rear = 0;
    int totalWaitingTime = 0, totalTurnAroundTime = 0, totalResponseTime = 0;
    int *queue = (int *)malloc(n * sizeof(int)); //creating the queue used in RR

    while (completed != n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                queue[rear++] = i;
                found = 1;
            }
        }

        if (!found) {
            printf("CPU is idle at time %d\n", time);
            time++;
            continue;
        }

        int index = queue[front++];
        if (processes[index].FirstTimeFlag == -1) {
            processes[index].CPUFirstTime = time;
            processes[index].FirstTimeFlag = 1;
        }

        if (processes[index].remainingTime <= timeQuantum) {
            time += processes[index].remainingTime;
            processes[index].completionTime = time;
            processes[index].turnAroundTime = processes[index].completionTime - processes[index].arrivalTime;
            processes[index].waitingTime = processes[index].turnAroundTime - processes[index].burstTime;
            processes[index].responseTime = processes[index].CPUFirstTime - processes[index].arrivalTime;

            totalWaitingTime += processes[index].waitingTime;
            totalTurnAroundTime += processes[index].turnAroundTime;
            totalResponseTime += processes[index].responseTime;
            processes[index].remainingTime = 0;
            completed++;
        } else {
            time += timeQuantum;
            processes[index].remainingTime -= timeQuantum;
            queue[rear++] = index;
        }
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnAroundTime / n;
    float averageResponseTime = (float)totalResponseTime / n;

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].turnAroundTime, processes[i].waitingTime, processes[i].responseTime);
    }

    printf("The average Turnaround Time is: %.2f\nThe average waiting time is: %.2f\nThe average response time is: %.2f\n", averageTurnaroundTime, averageWaitingTime, averageResponseTime);

    free(processes);
    free(queue);
    return 0;
}

/*INSTRUCTIONS TO RUN CODE
1. navigate to directory the program is stored in
2. run "gcc Assgn3SrcQ4-ArnabMandal.c"
3. run "./a.out"
*/
