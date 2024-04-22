 #include<iostream>
 using namespace std;

 const int max_r=10;
 const int max_p=10;

 int seq[max_p];

bool is_safe(int alloc[][max_r],int need[][max_r],int avai[],int n,int m)
{
    int work[max_r];
    bool finish[max_p]={false};

    for(int j=0;j<m;j++)
    {
        work[j]=avai[j];
    }
 for(int c=0;c<n;c++)
 {
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(finish[i]==false)
        {
        int flag=0;
        for(int j=0;j<m;j++)
        {
            if(need[i][j]>work[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=0;j<m;j++)
            {
                work[j]+=alloc[i][j];
            }
            finish[i]=true;
            seq[c]=i;
            found=1;
            break;
        }
        }
    }
 if(found==0)//for return statement
 {
    return 0;
 }
 }
 return 1;
}

 void display(int n)
 {
    for(int j=0;j<n;j++)
    {
        cout<<"->"<<seq[j];
    }
 }

 void res_req(int alloc[][max_r],int need[][max_r],int avai[],int req[],int n,int m,int id)
 {
    int flag=0;
        for(int j=0;j<m;j++)
        {
            if(req[j]>need[id][j])
            {
                flag=1;
                break;
            }
            if(req[j]>avai[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"Cannot Grant Request\n";
        }
        else
        {
        cout<<"System Pretends to give resources to process \n";
        for(int j=0;j<m;j++)    
        {
            avai[j]-=req[j];
            need[id][j]-=req[j];
            alloc[id][j]+=req[j];
        }
        if(is_safe(alloc,need,avai,n,m))
        {
            cout<<"\nRequest Granted";
            display(n);
        }
        else
        {
            cout<<"\nRequest leads to Deadlock in future so requesrt is not granted";
            for(int j=0;j<m;j++)
        {
            avai[j]+=req[j];
            need[id][j]+=req[j];
            alloc[id][j]-=req[j];
        }
        }
        }
 }


int main()
{
int n,m;
cout<<"Enter no of processes";
cin>>n;
cout<<"Enter no of resources";
cin>>m;

int alloc[max_p][max_r],max[max_p][max_r],avai[max_r],need[max_p][max_r],req[max_r],id;

cout<<"Enter max resources required to processes";
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
    cin>>max[i][j];
}
}
cout<<"Enter allocated resources for processes";
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
    cin>>alloc[i][j];
}
}
cout<<"Enter available vector";
for(int j=0;j<m;j++)
{
    cin>>avai[j];
}
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
    need[i][j]=max[i][j]-alloc[i][j];
}
}

bool x = is_safe(alloc,need,avai,n,m);
if(x==1)
cout<<"Safe sequence present\n";
display(n);
cout<<"\nEnter id";
cin>>id;
for(int j=0;j<m;j++)
{
    cin>>req[j];
}
res_req(alloc,need,avai,req,n,m,id);



    return 0;
 }