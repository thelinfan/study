#include<iostream>
#include<cstdio>
using namespace std;
void mergearray(int s[],int first,int mid,int last,int temp[]){
	int i=first,j=mid+1;
	int k=0;
	while (i<=mid&&j<=last){
		temp[k++]=s[i]<s[j]?s[i++]:s[j++];
	}
	while (i<=mid){
		temp[k++]=s[i++];
	}
	while (j<=last){
		temp[k++]=s[j++];
	}
	for (int i=0;i<k;i++){
		s[first+i]=temp[i];
	}
}
void mergesort(int s[],int first,int last,int temp[]){
	if (first<last){
		int mid=(first+last)/2;
		mergesort(s,first,mid,temp);
		mergesort(s,mid+1,last,temp);
		mergearray(s,first,mid,last,temp);
	}
}
bool Mergesort(int s[],int n){
	int *p=new int[n];
	if (p==NULL)
		return false;
	mergesort(s,0,n-1,p);
	delete[] p;
	return true;
}
int main(){
	int s[100];int n;
	cout<<"please input the number of arrary:";
	cin>>n;
	cout<<"please input the arrary:";
	for (int i=0;i<n;i++)
		cin>>s[i];
	Mergesort(s,n);
	for (int i=0;i<n;i++)
		cout<<s[i]<<" ";
	return 0;
}
