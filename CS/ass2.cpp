// FCFS:
#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    string name;
    float at, bt, st, tat, wt, ft;
} P[100];
int main()
{
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter process name : ";
        cin >> P[i].name;
        cout << "Enter arrival time : ";
        cin >> P[i].at;
        cout << "Enter burst time : ";
        cin >> P[i].bt;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (P[j + 1].at < P[j].at)
                swap(P[j], P[j + 1]);
        }
    }
    cout << endl;
    int temp = P[0].at;
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        P[i].ft = temp + P[i].bt;
        if (P[i + 1].at < P[i].ft)
            temp = P[i].ft;
        else
            temp = P[i + 1].at;
        P[i].tat = P[i].ft - P[i].at;
        P[i].wt = P[i].tat - P[i].bt;
        avg_tat = avg_tat + P[i].tat;
        avg_wt = avg_wt + P[i].wt;
    }
    cout << "Average time around time is " << avg_tat / n << endl;
    cout << "Average waiting time is " << avg_wt / n << endl
         << endl;
    cout << setw(5) << "Name" << setw(5) << "AT" << setw(5) << "BT" << setw(5) << "FT" << setw(5) << "TAT" << setw(5) << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << P[i].name << setw(5) << P[i].at << setw(5) << P[i].bt << setw(5) << P[i].ft << setw(5) << P[i].tat << setw(5) << P[i].wt << endl;
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << "----------------";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << "|\t" << P[i].name << "\t";
    cout << "|\n";
    for (int i = 0; i < n; i++)
        cout << "----------------";
    cout << "\n";
    cout << P[0].at << "\t\t";
    for (int i = 0; i < n; i++)
        cout << P[i].ft << "\t\t";
    cout << "\n";
    return 0;
}

// SJF:
#include <bits/stdc++.h>
using namespace std;
void gantt_chart(int processes, int at[], int bt[], int iterator)
{
    int ct[processes];
    int pro[10]{0};
    int l = 0;
    int nbt[processes];
    for (int i = 0; i < processes; i++)
        nbt[i] = bt[i];
    for (int i = 0; i < processes; i++)
        std::cout << "----------------";
    std::cout << std::endl;
    for (int arrival = 0; arrival < iterator; arrival++)
    {
        int process = -1;
        int min_bt = 1e7;
        int min_at = 1e7;
        for (int j = 0; j < processes; j++)
        {
            if (at[j] <= arrival)
            {
                if (bt[j] != 0 && bt[j] < min_bt)
                {
                    min_bt = bt[j];
                    min_at = at[j];
                    process = j;
                }
            }
        }
        for (int j = 0; j < processes; j++)
        {
            if (bt[j] == min_bt)
            {
                if (at[j] < min_at)
                {
                    min_at = at[j];
                    process = j;
                }
            }
        }
        if (process != -1)
        {
            bt[process] -= min_bt;
            arrival += min_bt - 1;
            if (bt[process] == 0)
                ct[process] = arrival + 1;
            std::cout << "|\t"
                      << "P" << process + 1 << "\t";
            pro[l] = process + 1;
            l++;
        }
        else
        {
            std::cout << "|\t"
                      << "-"
                      << "\t";
            pro[l] = -1;
            l++;
        }
    }
    std::cout << "|\n";
    for (int i = 0; i < processes; i++)
        std::cout << "----------------";
    std::cout << std::endl;
    std::cout << at[0] << "\t\t";
    for (int k = 0; k < processes; k++)
        std::cout << ct[k] << "\t\t";
    std::cout << "\n";
    int tat[processes], wt[processes], stat = 0, swt = 0;
    for (int i = 0; i < processes; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - nbt[i];
        stat = stat + tat[i];
        swt = swt + wt[i];
    }
    cout << setw(5) << "Name" << setw(5) << "AT" << setw(5) << "BT" << setw(5) << "FT" << setw(5) << "TAT" << setw(5) << "WT" << endl;
    for (int i = 0; i < processes; i++)
    {
        cout << setw(5) << "P" << (i + 1) << setw(5) << at[i] << setw(5) << nbt[i] << setw(5) << ct[i] << setw(5) << tat[i] << setw(5) << wt[i] << endl;
    }
    cout << "\nAverage TAT = " << (float)stat / (float)processes << endl;
    cout << "Average WT = " << (float)swt / (float)processes << endl;
    return;
}
int main()
{
    int processes;
    std::cout << "Enter the number of process: ";
    std::cin >> processes;
    int arrival_times[processes];
    int burst_times[processes];
    int iterator = 0;
    for (int i = 0; i < processes; i++)
    {
        std::cout << "Enter arrival time for process " << i + 1 << ": ";
        std::cin >> arrival_times[i];
    }
    for (int i = 0; i < processes; i++)
    {
        std::cout << "Enter burst time for process " << i + 1 << ": ";
        std::cin >> burst_times[i];
        iterator += burst_times[i];
    }
    std::cout << std::endl;
    gantt_chart(processes, arrival_times, burst_times, iterator);
}

// Priority:
#include <bits/stdc++.h>
using namespace std;
void gantt_chart(int processes, int at[], int bt[], int pt[], int iterator)
{
    int ct[processes], nbt[processes], nct[processes];
    int max = 1e7;
    for (int i = 0; i < processes; i++)
        nbt[i] = bt[i];
    for (int i = 0; i < processes; i++)
        std::cout << "----------------";
    cout << "\n|\t";
    int i = 0;
    for (int arrival = 0; arrival < iterator; arrival++)
    {
        int process = -1;
        int min_pt = 1e7;
        int min_at = 1e7;
        int min_bt;
        for (int j = 0; j < processes; j++)
        {
            if (at[j] <= arrival)
            {
                if (pt[j] < min_pt)
                {
                    min_pt = pt[j];
                    min_at = at[j];
                    min_bt = bt[j];
                    process = j;
                }
            }
        }
        for (int j = 0; j < processes; j++)
        {
            if (pt[j] == min_pt)
            {
                if (at[j] < min_at)
                {
                    min_at = at[j];
                    min_bt = bt[j];
                    process = j;
                }
            }
        }
        pt[process] = max;
        if (process != -1)
        {
            bt[process] -= min_bt;
            arrival += min_bt - 1;
            if (bt[process] == 0)
                ct[process] = arrival + 1;
            std::cout << "P" << process + 1 << "\t|\t";
            nct[i] = ct[process];
            i++;
        }
        else
        {
            std::cout << "P"
                      << "-1"
                      << " "
                      << "\t|\t";
            nct[i] = ct[process];
            i++;
        }
    }
    cout << endl;
    for (int i = 0; i < processes; i++)
        std::cout << "----------------";
    cout << "\n";
    cout << at[0] << "\t\t";
    for (int k = 0; k < processes; k++)
        std::cout << nct[k] << "\t\t";
    cout << "\n"
         << endl;
    int tat[processes], wt[processes], stat = 0, swt = 0;
    for (int i = 0; i < processes; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - nbt[i];
        stat = stat + tat[i];
        swt = swt + wt[i];
    }
    cout << setw(5) << "Name" << setw(5) << "AT" << setw(5) << "BT" << setw(5) << "FT" << setw(5) << "TAT" << setw(5) << "WT" << endl;
    for (int i = 0; i < processes; i++)
        cout << setw(5) << "P" << (i + 1) << setw(5) << at[i] << setw(5) << nbt[i] << setw(5) << ct[i] << setw(5) << tat[i] << setw(5) << wt[i] << endl;
    cout << "\nAverage TAT = " << (float)stat / (float)processes << endl;
    cout << "Average WT = " << (float)swt / (float)processes << endl;
    return;
}
int main()
{
    int processes;
    std::cout << "Enter the number of process: ";
    std::cin >> processes;
    int arrival_times[processes];
    int burst_times[processes];
    int priority[processes];
    int iterator = 0;
    for (int i = 0; i < processes; i++)
    {
        std::cout << "Enter arrival time for process " << i + 1 << ": ";
        std::cin >> arrival_times[i];
    }
    for (int i = 0; i < processes; i++)
    {
        std::cout << "Enter priority for process " << i + 1 << ": ";
        std::cin >> priority[i];
    }
    for (int i = 0; i < processes; i++)
    {
        std::cout << "Enter burst time for process " << i + 1 << ": ";
        std::cin >> burst_times[i];
        iterator += burst_times[i];
    }
    gantt_chart(processes, arrival_times, burst_times, priority, iterator);
}

// Round Robin:
#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int AT, BT, ST[20], WT, FT, TAT, pos;
};
int quant;
int main()
{
    int n, i, j;
    cout << "Enter the no. of processes: ";
    cin >> n;
    Process p[n];
    cout << "Enter the quantum: ";
    cin >> quant;
    cout << "Enter the process numbers: ";
    for (i = 0; i < n; i++)
        cin >> p[i].pos;
    cout << "Enter the Arrival time of processes: ";
    for (i = 0; i < n; i++)
        cin >> p[i].AT;
    cout << "Enter the Burst time of processes: ";
    for (i = 0; i < n; i++)
        cin >> p[i].BT;
    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];
    int index = -1;
    for (i = 0; i < n; i++)
    {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++)
            s[i][j] = -1;
    }
    int tot_wt, tot_tat;
    tot_wt = 0;
    tot_tat = 0;
    bool flag = false;
    while (c != 0)
    {
        mini = INT_MAX;
        flag = false;
        for (i = 0; i < n; i++)
        {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0)
            {
                index = i;
                mini = a[i];
                flag = true;
            }
        }
        if (!flag)
        {
            time++;
            continue;
        }
        j = 0;
        while (s[index][j] != -1)
            j++;
        if (s[index][j] == -1)
        {
            s[index][j] = time;
            p[index].ST[j] = time;
        }
        if (b[index] <= quant)
        {
            time += b[index];
            b[index] = 0;
        }
        else
        {
            time += quant;
            b[index] -= quant;
        }
        if (b[index] > 0)
            a[index] = time + 0.1;
        if (b[index] == 0)
        {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    }
    cout << setw(5) << "Name" << setw(5) << "AT" << setw(5) << "BT" << setw(5) << "FT" << setw(5) << "TAT" << setw(5) << "WT" << endl;
    for (int i = 0; i < n; i++)
        cout << setw(5) << "P" << (i + 1) << setw(5) << p[i].AT << setw(5) << p[i].BT << setw(5) << p[i].FT << setw(5) << p[i].TAT << setw(5) << p[i].WT << endl;
    cout << "\n\n"
         << endl;
    std::map<int, int> myMap;
    for (int i = 0; i < n; i++)
        myMap.insert(std::make_pair(p[i].FT, p[i].pos));
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << "----------------";
    std::cout << std::endl;
    cout << "|\t";
    for (const auto &pair : myMap)
        std::cout << "P" << pair.second << "\t|\t";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << "----------------";
    std::cout << std::endl;
    int minAT = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].AT < minAT)
            minAT = p[i].AT;
    }
    cout << "\n"
         << minAT << "\t\t";
    for (const auto &pair : myMap)
        std::cout << pair.first << "\t\t";
    cout << "\n"
         << endl;
    double avg_wt, avg_tat;
    avg_wt = tot_wt / static_cast<double>(n);
    avg_tat = tot_tat / static_cast<double>(n);
    cout << "The average wait time is: " << avg_wt << endl;
    cout << "The average TurnAround time is: " << avg_tat << endl;
    return 0;
}
