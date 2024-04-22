#include<iostream>
using namespace std;

//SSTF
void sstf(int arr[],int head,int n)
{
    int near,ind,seek_time=0,fseq[n],flag[n];

for(int j=0;j<n;j++)
{
    flag[j]=0;
}

for(int j=0;j<n;j++)
{
    int min=99999;
for(int i=0;i<n;i++)
{
    if(abs(head-arr[i])<=min && flag[i]==0)
    {
        min=abs(head-arr[i]);
        near=arr[i];
        ind=i;
    }
}
flag[ind]=1;
fseq[j]=near;
seek_time+=abs(head-near);
head=near;
}
cout<<endl;
cout<<seek_time<<endl;

for(int i=0;i<n;i++)
{
    cout<<fseq[i]<<"\n";
}
}

//FCFS
void fcfs(int arr[],int head,int n)
{
    int seek_time=0;
for(int i=0;i<n;i++)
{
    seek_time+=abs(head-arr[i]);
    head=arr[i];
}
cout<<"seek sequence is:-\n";
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<"\n";
}

cout<<"seek time required is "<<seek_time;
}

int main()
{
    int n,head;
    cout<<"enter number of request\n";
    cin>>n;
    int seq[n];
    cout<<"Enter sequence for accessing\n";
    for(int i=0;i<n;i++)
    {
    cin>>seq[i];
    }
    cout<<"Enter head pointer\n";
    cin>>head;

    sstf(seq,head,n);
    fcfs(seq,head,n);
return 0;
}