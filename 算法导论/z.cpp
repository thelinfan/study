
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[20][20];
char bc[5][5];
struct weizhi
{
    char s;
    int x;
    int y;
};
int gj(weizhi w,int x,int y)
{
    char c=w.s;
    int hx=w.x;
    int hy=w.y;
    switch(c)
    {
    case 'G':
        if (y!=hy)
            return -1;
        for (int i=x+1;i<hx;i++)
            if (s[i][y]!='*')
                return -1;
        return 1;
    case 'R':
        if (x!=hx&&y!=hy)
            return -1;
        if (x==hx)
        {
            int miny,maxy;
            miny=y<hy?y:hy;
            maxy=y>hy?y:hy;
            for (int i=miny+1;i<maxy;i++)
                if (s[x][i]!='*')
                    return -1;
            return 1;
        }
        if (y==hy)
        {
            int minx,maxx;
            minx=x<hx?x:hx;
            maxx=x>hx?x:hx;
            for (int i=minx+1;i<maxx;i++)
                if (s[i][y]!='*')
                    return -1;
            return 1;
        }
    case 'H':
        if ((fabs(x-hx)==2&&fabs(y-hy)==1)||(fabs(x-hx)==1&&fabs(y-hy)==2))
        {
            if (s[x-1][y-1]=='*'&&(s[x-2][y-1]=='H'||s[x-1][y-2]=='H'))
                return 1;
            if (s[x-1][y+1]=='*'&&(s[x-2][y+1]=='H'||s[x-1][y+2]=='H'))
                return 1;
            if (s[x+1][y+1]=='*'&&(s[x+1][y+2]=='H'||s[x+2][y+1]=='H'))
                return 1;
            if (s[x+1][y-1]=='*'&&(s[x+1][y-2]=='H'||s[x+2][y-1]=='H'))
                return 1;
        }
        return -1;
    case 'C':
        if (x!=hx&&y!=hy)
            return -1;
        if (x==hx)
        {
            int c=0;
            int miny,maxy;
            miny=y<hy?y:hy;
            maxy=y>hy?y:hy;
            for (int i=miny+1;i<maxy;i++)
                if (s[x][i]!='*')
                    c++;
            if (c==1)
                return 1;
            return -1;
        }
        if (y==hy)
        {
            int c=0;
            int minx,maxx;
            minx=x<hx?x:hx;
            maxx=x>hx?x:hx;
            for (int i=minx+1;i<maxx;i++)
                if (s[i][y]!='*')
                    c++;
            if (c==1)
                return 1;
            return -1;
        }
    }
}
int pd(int x,int y,int n,weizhi w[])
{
    int c=0;
    for (int i=1;i<=n;i++)
    {
        if (!(x==w[i].x&&y==w[i].y))
       {
            if (gj(w[i],x,y)==1)
                c++;
       }
    }
    if (c>0)
        return 1;
    else return -1;
}

int main()
{
    int n,x,y;
    while(scanf("%d%d%d",&n,&x,&y)&&(!(n==0&&x==0&&y==0)))
    {
        memset(s,'*',sizeof(s));
        weizhi w[20];
        for (int i=1;i<=n;i++)
        {
            cin>>w[i].s;
            scanf("%d%d",&w[i].x,&w[i].y);
            s[w[i].x][w[i].y]=w[i].s;
        }
        int c=0;
        if (x==1&&y==4)
        {
            if (pd(x+1,y,n,w)==1)
                c++;

            if (pd(x,y+1,n,w)==1)
                c++;
            if (c==2)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==1&&y==5)
        {
            if (pd(x,y-1,n,w)==1)
                c++;

            if (pd(x,y+1,n,w)==1)
                c++;

            if (pd(x+1,y,n,w)==1)
                c++;
            if (c==3)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==1&&y==6)
        {

            if (pd(x,y-1,n,w)==1)
                c++;

            if (pd(x+1,y,n,w)==1)
                c++;
            if (c==2)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==2&&y==4)
        {

            if (pd(x-1,y,n,w)==1)
                c++;

            if (pd(x+1,y,n,w)==1)
                c++;

            if (pd(x,y+1,n,w)==1)
                c++;
            if (c==3)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==2&&y==5)
        {

            if (pd(x-1,y,n,w)==1)
                c++;

            if (pd(x+1,y,n,w)==1)
                c++;

            if (pd(x,y-1,n,w)==1)
                c++;

            if (pd(x,y+1,n,w)==1)
                c++;
            if (c==4)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==2&&y==6)
        {

            if (pd(x-1,y,n,w)==1)
                c++;

            if (pd(x,y-1,n,w)==1)
                c++;

            if (pd(x+1,y,n,w)==1)
                c++;
            if (c==3)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==3&&y==4)
        {

            if (pd(x-1,y,n,w)==1)
                c++;

            if (pd(x,y+1,n,w)==1)
                c++;
            if (c==2)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==3&&y==5)
        {

            if (pd(x-1,y,n,w)==1)
                c++;

            if (pd(x,y-1,n,w)==1)
                c++;

            if (pd(x,y+1,n,w)==1)
                c++;
            if (c==3)
                printf("YES\n");
            else printf("NO\n");
        }else if (x==3&&y==6)
        {

            if (pd(x-1,y,n,w)==1)
                c++;

            if (pd(x,y-1,n,w)==1)
                c++;
            if (c==2)
                printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
