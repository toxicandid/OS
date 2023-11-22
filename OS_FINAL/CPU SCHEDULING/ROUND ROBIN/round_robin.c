#include <stdio.h>

struct pro
{
    int PN;
    int BT;
    int AT;
    int CT;
    int TT;
    int WT;
    int remainingBT; // To keep track of remaining burst time for a process
};

void roundRobin(struct pro p[], int n, int quantum)
{
    int time = 0;      // Current time
    int completed = 0; // Number of processes completed

    // Keep executing until all processes are completed
    while (completed < n)
    {
        int flag = 0; // Flag to check if any process is executed in this iteration

        for (int i = 0; i < n; i++)
        {
            // Check if the process has arrived and is not completed
            if (p[i].AT <= time && p[i].remainingBT > 0)
            {
                // Execute the process for the minimum of quantum or remaining burst time
                int executeTime = (p[i].remainingBT > quantum) ? quantum : p[i].remainingBT;
                time += executeTime;
                p[i].remainingBT -= executeTime;

                // Update completion time if the process is completed
                if (p[i].remainingBT == 0)
                {
                    p[i].CT = time;
                    p[i].TT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TT - p[i].BT;
                    completed++;
                }

                flag = 1; // Set the flag to indicate that a process is executed in this iteration
            }
        }

        // If no process is executed in this iteration, increment time
        if (flag == 0)
        {
            time++;
        }
    }
}

int main()
{
    int n, quantum;
    printf("Enter number of processes:");
    scanf("%d", &n);
    printf("Enter time quantum for Round Robin:");
    scanf("%d", &quantum);

    struct pro p[n];
    printf("Enter process details\n");
    for (int i = 0; i < n; i++)
    {
        p[i].PN = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &p[i].AT);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].BT);
        p[i].remainingBT = p[i].BT; // Initialize remaining burst time
    }

    roundRobin(p, n, quantum);

    float totalt = 0, totalw = 0;
    printf("PN\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PN, p[i].AT, p[i].BT, p[i].CT, p[i].TT, p[i].WT);
        totalt += p[i].TT;
        totalw += p[i].WT;
    }
    printf("Average TT:%f\n", totalt / n);
    printf("Average WT:%f\n", totalw / n);

    return 0;
}

