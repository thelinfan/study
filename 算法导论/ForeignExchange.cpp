#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
const int maxn=1000000+10000;
struct jh
{
    int x;
    int y;
};
bool com(jh s1,jh s2)
{
    if (s1.x<s2.x)
        return true;
    else if (s1.x==s2.x&&s1.y<=s2.y)
        return true;
    return false;
}
jh s[maxn];
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)&&n!=0)
    {
        int x,y;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            if (x>y)
            {
                s[i].x=y;
                s[i].y=x;
            }else
            {
                s[i].x=x;
                s[i].y=y;
            }
        }
        sort(s+1,s+n+1,com);
        int cc=0;
        for (int i=1;i<=n;)
        {
            if (s[i].x!=s[i].y)
            {
                if (s[i].x==s[i+1].x&&s[i].y==s[i+1].y)
                {
                    cc+=2;;
                    i+=2;
                }
                else i++;
            }else if (s[i].x==s[i].y)
            {
                cc++;
                i++;
            }
        }
        if (cc==n)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
