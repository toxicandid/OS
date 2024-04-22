//Assiga(bf,nf,ff,wf) 6
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nb, np, choice;
    cout << "Enter number of blocks : ";
    cin >> nb;
    cout << "Enter number of processes : ";
    cin >> np;
    int blocks[nb], processes[np];
    cout << "Enter the blocks array :" << endl;
    for (int i = 0; i < nb; i++)
        cin >> blocks[i];
    cout << "Enter the processes array :" << endl;
    for (int i = 0; i < np; i++)
        cin >> processes[i];
    int flag = 0;
    cout << "1. First Fit\n2. Next Fit\n3. Best Fit\n4. Worst Fit" << endl;
    cout << "Enter method : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        for (int i = 0; i < np; i++)
        {
            for (int j = 0; j < nb; j++)
            {
                if (processes[i] <= blocks[j])
                {
                    blocks[j] -= processes[i];
                    flag = 1;
                    cout << "Process " << i << " has been allocated to block"
                                               <<blocks[j]+processes[i]<<" creating a hole of "<<blocks[j]<<endl;
                        break;
                }
            }
            if (flag == 0)
                cout << "The process " << i << " can not be allocated any space" << endl;
            flag = 0;
        }
        break;
    }
    case 2:
    {
        int x = 0, cnt = 0;
        for (int i = 0; i < np; i++)
        {
            for (int j = x; j < nb; j = (j + 1) % nb)
            {
                if (processes[i] <= blocks[j])
                {
                    blocks[j] -= processes[i];
                    flag = 1;
                    cout << "Process " << i << " has been allocated to block"
                                               <<blocks[j]+processes[i]<<" creating a hole of "<<blocks[j]<<endl;
                        x = j;
                    break;
                }
                cnt++;
                if (cnt == nb - 1)
                    break;
            }
            if (flag == 0)
                cout << "The process " << i << " can not be allocated any space" << endl;
            flag = 0;
            cnt = 0;
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < np; i++)
        {
            int min = 999, minIndex;
            for (int j = 0; j < nb; j++)
            {
                if (processes[i] <= blocks[j] && blocks[j] < min)
                {
                    min = blocks[j];
                    minIndex = j;
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                blocks[minIndex] -= processes[i];
                cout << "Process " << i << " has been allocated to block"
                                           <<blocks[minIndex]+processes[i]<<" creating a hole of "<<blocks[minIndex]<<endl;
            }
            if (flag == 0)
                cout << "The process " << i << " can not be allocated any space" << endl;
            flag = 0;
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < np; i++)
        {
            int max = 0, maxIndex;
            for (int j = 0; j < nb; j++)
            {
                if (processes[i] <= blocks[j] && blocks[j] > max)
                {
                    max = blocks[j];
                    maxIndex = j;
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                blocks[maxIndex] -= processes[i];
                cout << "Process " << i << " has been allocated to block"
                                           <<blocks[maxIndex]+processes[i]<<" creating a hole of "<<blocks[maxIndex]<<endl;
            }
            if (flag == 0)
                cout << "The process " << i << " can not be allocated any space" << endl;
            flag = 0;
        }
        break;
    }
    }
    return 0;
}
