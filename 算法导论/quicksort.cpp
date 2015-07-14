#include<iostream>
#define N 1000
void change(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int quick_partition(int s[],int l,int r)
{
    int key=s[r];
    int i=l-1;
    int j;
    for (j=l;j<r;j++)
    {
        if (s[j]<key)
        {
            change(s[++i],s[j]);
        }
    }
    change(s[++i],s[r]);
    return i;
}
void quicksort(int s[],int l,int r)
{
    int q;
    if (l<r)
    {
        q=quick_partition(s,l,r);
        quicksort(s,l,q-1);
        quicksort(s,q+1,r);
    }
}
using namespace std;
int main()
{
    int n;
    int s[N];
    cout<<"Please input the number of array:";
    cin>>n;
    cout<<"Please input the array:";
    for (int i=0;i<n;i++)
        cin>>s[i];
        quicksort(s,0,n-1);
    for (int i=0;i<n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
    return 0;
}
