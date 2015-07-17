#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pd(char s[],int min,int n)
{
	if (n%min!=0)
	  return -1;
	int r=n/min;
	for (int i=1;i<r;i++)
	{
			for (int j=0;j<min;j++)
			{
					if (s[j]!=s[j+i*min])
					  return -1;
			}
	}
	return 1;
}
int count(char s[],int n)
{
	int min;
	for (min=1;min<=n;min++)
	{
			if (pd(s,min,n)==1)
			  return min;
	}
}
int main()
{
	int n;
	char s[100];
	cin>>n;
	while(n--)
	{
		int len;
			getchar();
			cin>>s;
			len=strlen(s);
			int min;
			min=count(s,len);
			cout<<min<<endl;
			if (n)
			  cout<<endl;
	}
	return 0;
}
