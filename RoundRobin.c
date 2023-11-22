#include<stdio.h>

int main()
{
  // Declare variables
  int cnt, j, n, t, remain, flag = 0, tq;
  int wt = 0, tat = 0;
  int at[10], bt[10], rt[10]; // at: arrival time, bt: burst time, rt: remaining time

  // Get the total number of processes
  printf("Enter Total Process:\t ");
  scanf("%d", &n);

  // Get the arrival time and burst time for each process
  for (cnt = 0; cnt < n; cnt++) {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :", cnt + 1);
    scanf("%d", &at[cnt]);
    scanf("%d", &bt[cnt]);
    rt[cnt] = bt[cnt]; // Initialize the remaining time to the burst time
  }

  // Get the time quantum
  printf("Enter Time Quantum:\t");
  scanf("%d", &tq);

  // Print the header row
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

  // Start the round robin scheduling algorithm
  for (t = 0, cnt = 0; remain != 0;) {
    // If the remaining time of the current process is less than or equal to the time quantum,
    // execute the process completely
    if (rt[cnt] <= tq && rt[cnt] > 0) {
      t += rt[cnt];
      rt[cnt] = 0;
      flag = 1; // Set the flag to indicate that the process has finished executing
    } else if (rt[cnt] > 0) {
      // Otherwise, reduce the remaining time of the process by the time quantum
      rt[cnt] -= tq;
      t += tq;
    }

    // If the process has finished executing,
    // print the turnaround time and waiting time for the process
    if (rt[cnt] == 0 && flag == 1) {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n", cnt + 1, t - at[cnt], t - at[cnt] - bt[cnt]);
      wt += t - at[cnt] - bt[cnt]; // Calculate the waiting time for the process
      tat += t - at[cnt]; // Calculate the turnaround time for the process
      flag = 0;
    }

    // Move to the next process
    if (cnt == n - 1) {
      cnt = 0;
    } else if (at[cnt + 1] <= t) {
      cnt++;
    } else {
      cnt = 0;
    }
  }

  // Calculate the average waiting time and average turnaround time
  printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
  printf("Avg Turnaround Time = %f", tat * 1.0 / n);

  return 0;
}
