#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int s[20][100];
void change(int n){
	int m=s[n][0];
	int i;
	for (i=1;;i++){
		if (m==0)
			break;
		s[n][i]=m%2;
		m=m/2;
	}
	if (s[n][0]==0){
		i++;
		s[n][1]=0;
	}
	i--;
	//for (int j=1;j<32;j++)
	//	cout<<s[n][j];
	//cout<<endl;
}
int js(){
	int dw1,dw0,dw,jw=0;
	for (int i=1;i<32;i++){
		dw=0;
		for (int j=1;j<=8;j++){
			dw+=(s[j][i]^1);
		}
		if ((jw+dw)%2^1==s[9][i]){
			s[10][i]=1;
		}else {
			s[10][i]=0;
			dw=8-dw;
		}
		jw=(jw+dw)/2;
	}
	int sum=0;
	for (int i=1;i<=32;i++)
		sum+=s[10][i]*pow(2,i-1);
	cout<<sum<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		memset(s,0,sizeof(s));
		for (int i=1;i<=9;i++){
			scanf("%d",&s[i][0]);
			change(i);
		}
		js();
	}
	return 0;
}
