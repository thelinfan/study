#include<iostream>
#include<cstdio>
#include<cstring>
char s[60][1100];
int jl[4][1100];
char cc[1100];
using namespace std;
int main()
{
    int co;
    scanf("%d",&co);getchar();
    for (int coi=0;coi<co;coi++)
    {
        memset(jl,0,sizeof(jl));
        memset(cc,'A',sizeof(cc));
        int x,y;
        scanf("%d%d",&x,&y);getchar();
        for (int i=0;i<x;i++)
            scanf("%s",s[i]);
        getchar();

        int max=0;
        for (int j=0;j<y;j++)
        {
            for (int i=0;i<x;i++)
            {
                switch(s[i][j])
                {
                    case 'A':jl[0][j]++;break;
                    case 'C':jl[1][j]++;break;
                    case 'G':jl[2][j]++;break;
                    case 'T':jl[3][j]++;break;
                }
            }
            max=jl[0][j];
            cc[j]='A';
            for (int i=1;i<4;i++)
            {
                if (jl[i][j]>max)
                {
                    max=jl[i][j];
                    switch(i)
                    {
                        case 1: cc[j]='C';break;
                        case 2: cc[j]='G';break;
                        case 3: cc[j]='T';break;
                    }
                }
            }
        }
        cc[y]='\0';
        printf("%s\n",cc);
        int counte=0;
        for (int i=0;i<x;i++)
        {
            for (int j=0;j<y;j++)
            {
                if (s[i][j]!=cc[j])
                    counte++;
            }
        }
        printf("%d\n",counte);
    }
    return 0;
}
