#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const long long maxn=100000+200;
struct pony
{
    int si;
    int mi;
    int ri;
};
struct instruct
{
    int ti;
    int li;
    int ri;
};
pony p[maxn];
instruct I[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].si,&p[i].mi,&p[i].ri);
    int m;
    scanf("%d",&m);
    int st=0;
    for (int i=1;i<=m;i++)
    {
        int sum=0;
        scanf("%d%d%d",&I[i].ti,&I[i].li,&I[i].ri);
        for (int j=1;j<=n;j++)
        {
            int temp=(I[i].ti-st)*p[j].ri+p[j].si;
            p[j].si=(temp<p[j].mi?temp:p[j].mi);
            if (j>=I[i].li&&j<=I[i].ri)
            {
                sum+=p[j].si;
                p[j].si=0;
            }
        }
        st=I[i].ti;
        cout<<sum<<endl;
    }

    return 0;
}
