#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1000000+10000;
int s[maxn];
int n,c;
bool judge(int m){ 
    int last=0;
    for (int i=1;i<c;i++){
        int fr=last+1;
        while (fr<n&&s[fr]-s[last]<m)
            fr++;
        if (fr==n)
            return false;
        last=fr;
    }   
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&c);
        for (int i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);    
        int l=1,r=maxn;
        for (int i=1;i<100;i++){
            int m=(l+r)/2;
            if (judge(m))
                l=m;
            else r=m;    
        }
        cout<<l<<endl;
    }   
    return 0;
}
