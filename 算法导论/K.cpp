#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    double zs[15][35];
    long long xs[15][35];
    for(int i=0; i<=9;++i)
        for(int j=1;j<=30;++j)
        {
            double m=1-pow(2,-1-i),e=pow(2,j)-1;
            double t=log10(m)+e*log10(2);
            xs[i][j]= t,zs[i][j]=pow(10,t-xs[i][j]);
        }
    string s;
    while (cin>>s&&s!="0e0")
    {
        for (int i=0;i<s.size();i++)
            s[i]=s[i]-'0';
        double A=s[0];int B=0;
        for (int i=2;i<17;i++)
        {
            A+=(s[i]*pow(10,-i+1));
        }
        for (int i=18;i<s.size();i++)
        {
            B=B*10+s[i];
        }
        double x=log10(A*pow(10,B));
        while(A<1) A*=10,B--;
        int key=-1;
        for(int i=0;i<=9;i++)
        {
            for (int j=1;j<=30;j++)
            {
                if ((B==xs[i][j])&&(fabs(A-zs[i][j])<1e-4||fabs(A/10-zs[i][j])<1e-4))
                {
                   printf("%d %d\n",i,j);
                   key=1;
                   break;
                }
            }
            if (key==1)
                break;
        }
    }
}
