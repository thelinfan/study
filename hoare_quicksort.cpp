#include<iostream>
#define N 1000
using namespace std;
int hoare_partition(int A[],int p,int r)
{
    int x=A[p];
    int i=p;
    int j=r+1;
    while(1)
    {
        while (A[++i]<x);
        while (A[--j]>x);
        if (i<j)
        {
            A[i]=A[i]+A[j];
            A[j]=A[i]-A[j];
            A[i]=A[i]-A[j];
        }else
        {
            A[p]=A[j];
            A[j]=x;
            return j;
        }
    }

}
void hoare(int A[],int p,int r)
{
    int q;
    if (p<r)
    {
        q=hoare_partition(A,p,r);
        hoare(A,p,q-1);
        hoare(A,q+1,r);
    }
}
int main()
{
    int n;
    int s[N];
    cout<<"Please input the number of array:";
    cin>>n;
    cout<<"Please input the array:";
    for (int i=0;i<n;i++)
        cin>>s[i];
        hoare(s,0,n-1);
    for (int i=0;i<n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
    return 0;
}
