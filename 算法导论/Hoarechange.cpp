#include<iostream>
using namespace std;
#define N 1000
void change(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int hoarechange_part(int s[],int l,int r)
{
    int key=s[l];
    int i=l;
    int j=r;
    while (i<j)
    {
        while (s[j]>=key&&i<j)
            j--;
        s[i]=s[j];
        while (s[i]<=key&&i<j)
            i++;
        s[j]=s[i];
    }
    s[i]=key;
    return i;
}
void hoarechange(int A[],int p,int r)
{
    int q;
    if (p<r)
    {
        q=hoarechange_part(A,p,r);
        hoarechange(A,p,q-1);
        hoarechange(A,q+1,r);
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
        hoarechange(s,0,n-1);
    for (int i=0;i<n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
    return 0;
}
