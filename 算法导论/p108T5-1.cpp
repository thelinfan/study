
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int s[100100],we[100100];
int main()
{
    int n,q;
    int ci=1;
    while (scanf("%d%d",&n,&q)!=EOF&&n!=0&&q!=0)
    {
        printf("CASE# %d:\n",ci++);
        for (int i=1;i<=n;i++)
            scanf("%d",&s[i]);
        sort(s+1,s+n+1);
        for (int i=1;i<=q;i++)
        {
            scanf("%d",&we[i]);
            int x=lower_bound(s+1,s+n+1,we[i])-s;
            if (s[x]==we[i]) printf("%d found at %d\n",we[i],x);
            else printf("%d not found\n",we[i]);
        }


    }
    return 0;
}
