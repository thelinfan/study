#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
int s[101000];
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum,t;sum=t=0;int temp;
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&temp);
            while (t>1&&s[t]<=s[t-1]&&s[t]<=temp)
            {
                sum+=(min(s[t-1],temp));
                t--;
            }
            t++;
            s[t]=temp;
        }
        sort(s+1,s+t+1);
        for (int i=1;i<=t-2;i++)
           cout<<s[i]<<endl;
           //sum+=s[i];
        // printf("%d\n",sum);
    }
    return 0;
}
