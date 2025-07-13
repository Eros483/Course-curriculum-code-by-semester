#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int waitingTime;
    int burstTime;
    int turnAroundTime;
    int priority;
    int arrivalTime;
    int completionTime;
    int processCompletedFlag;
} Process;

void sortByPriority(Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) { 
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("THIS IS PRIORITY (NON-PREEMPTIVE) SCHEDULING ALGORITHM\n");
    printf("Higher the priority value, greater the priority\n");

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].id=i+1;
        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].processCompletedFlag = -1;
    }

    int noOfProcessesCompleted = 0, time = 0;
    
    while (noOfProcessesCompleted != n) {
        int minPriorityIdx = -1;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].processCompletedFlag == -1) {
                if (minPriorityIdx == -1 || processes[i].priority > processes[minPriorityIdx].priority) {
                    minPriorityIdx = i;
                }
            }
        }

        if (minPriorityIdx == -1) {
            time++; // No process is ready, so increase time
        } else {
            time += processes[minPriorityIdx].burstTime;
            processes[minPriorityIdx].completionTime = time;
            processes[minPriorityIdx].turnAroundTime = processes[minPriorityIdx].completionTime - processes[minPriorityIdx].arrivalTime;
            processes[minPriorityIdx].waitingTime = processes[minPriorityIdx].turnAroundTime - processes[minPriorityIdx].burstTime;
            processes[minPriorityIdx].processCompletedFlag = 1;
            noOfProcessesCompleted++;
        }
    }

    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnAroundTime / n;

    printf("The average Turnaround Time is: %.2f\n", averageTurnaroundTime);
    printf("The average Waiting Time is: %.2f\n", averageWaitingTime);
    printf("The average Response Time is: %.2f\n", averageWaitingTime);

    free(processes);
    return 0;
}

/*INSTRUCTIONS TO RUN CODE
1. navigate to directory the program is stored in
2. run "gcc Assgn3SrcQ5-ArnabMandal.c"
3. run "./a.out"
*/
