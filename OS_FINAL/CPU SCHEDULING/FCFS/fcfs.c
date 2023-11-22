#include <stdio.h>

struct pro
{
    int PN;
    int BT;
    int AT;
    int CT;
    int TT;
    int WT;
};

void sorta(struct pro p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i].AT < p[j].AT)
            {
                struct pro temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);
    struct pro p[n];
    printf("Enter process details\n");
    for (int i = 0; i < n; i++)
    {
        p[i].PN = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &p[i].AT);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].BT);
    }
    sorta(p, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", p[i].PN, p[i].AT, p[i].BT);
    }
    int t = p[0].AT;
    for (int i = 0; i < n; i++)
    {
        if (p[i].AT <= t)
        {
            t += p[i].BT;
            p[i].CT = t;
        }
        else
        {
            t = p[i].AT;
            t += p[i].BT;
            p[i].CT = t;
        }
        p[i].TT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TT - p[i].BT;
    }
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

