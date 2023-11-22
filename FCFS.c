#include<stdio.h>

// Structure to represent a process
struct Procedure {
    int Proc, at, bt, tt, wt;
};

// Array to store processes
struct Procedure p[10];

// Function to sort processes based on arrival time
void sort(int);

// Function to calculate turnaround time and waiting time for each process
void calculate(int);

int main() {
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes you want to enter:\t");
    scanf("%d", &n);

    // Get process details (Process Number, Arrival Time, Burst Time) from the user
    printf("Enter your Process Number, Arrival time, Burst Time\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].Proc);
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
    }

    // Display the entered process details
    printf("PROCEDURE\tAT\tBT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\n", p[i].Proc, p[i].at, p[i].bt);

    // Sort processes based on arrival time
    sort(n);

    // Calculate turnaround time and waiting time for each process
    calculate(n);

    // Display the sorted and calculated process details
    printf("PROCEDURE\tAT\tBT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\t%d\t%d\n", p[i].Proc, p[i].at, p[i].bt, p[i].tt, p[i].wt);

    return 0;
}

// Function to sort processes based on arrival time using Bubble Sort
void sort(int n) {
    struct Procedure temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Display the sorted process details
    printf("SORTED\n\nPROCEDURE\tAT\tBT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\n", p[i].Proc, p[i].at, p[i].bt);
}

// Function to calculate turnaround time and waiting time for each process
void calculate(int n) {
    p[0].tt = p[0].at + p[0].bt;
    for (int i = 1; i < n; i++) {
        if (p[i].at < p[i - 1].tt)
            p[i].tt = p[i].bt + p[i - 1].tt;
        else
            p[i].tt = p[i].bt + (3 * p[i - 1].tt - p[i].at);
    }

    // Calculate turnaround time and waiting time, and update averages
    double avgtt = 0, avgwt = 0;
    for (int i = 0; i < n; i++) {
        p[i].tt = p[i].tt - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        avgtt += p[i].tt;
        avgwt += p[i].wt;
    }

    // Display average turnaround time and average waiting time
    printf("Average TT is %f and Average WT is %f\n", avgtt / n, avgwt / n);
}
