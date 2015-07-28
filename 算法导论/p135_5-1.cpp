#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1000+100;
char s[2000][maxn];
int cdz[maxn][maxn]={0};
int dz[maxn]={0};
int main()
{
    int i=0,j=0;
    int maxy=0;
    while (scanf("%c",&s[i][j])!=EOF)
    {
        if ((s[i][j]==' '&&s[i][j-1]==' ')||(s[i][j]==' '&&j==0))
        {
             j--;
        }
        else if (s[i][j]=='\n')
        {
            i++;
            if (j+1>maxy)
                maxy=j+1;
            j=0;
            continue;
        }
        j++;
    }

    for (int n=0;n<i;n++)
    {
        for (int m=0;m<maxy;m++)
        {
            printf("%c",s[n][m]);
            if (s[n][m]=='\n')
                break;
        }
    }
}
