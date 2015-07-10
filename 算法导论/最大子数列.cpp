#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int find_max_crossing_subarray(int A[],int low,int mid,int high){
	int left_sum,right_sum;left_sum=right_sum=-100000;
	int max_left,max_right;
	int sum;
	sum=0;
	for (int i=mid;i>=low;i--){
		sum+=A[i];
		if (sum>left_sum){
			left_sum=sum;
			max_left=i;
		}
	}
	sum=0;
	for (int j=mid+1;j<=high;j++){
		sum+=A[j];
		if (sum>right_sum){
			right_sum=sum;
			max_right=j;
		}
	}
	return right_sum+left_sum;
}
int find_maximum_subarray(int A[],int low,int high){
	int mid,left_sum,right_sum,cross_sum;
	if (high==low){
		return A[low];
	}else {
		mid=(low+high)/2;
		left_sum=find_maximum_subarray(A,low,mid);
		right_sum=find_maximum_subarray(A,mid+1,high);
		cross_sum=find_max_crossing_subarray(A,low,mid,high);
	}
	if (left_sum>right_sum&&left_sum>cross_sum){
		return left_sum;
	}
	else if (right_sum>left_sum&&right_sum>cross_sum){
		return right_sum;
	}
	else return cross_sum;
}
int main(){
	int s[100];
	int n;
	cout<<"input length:";
	cin>>n;
	cout<<"input s[]:";
	for (int i=0;i<n;i++)
		cin>>s[i];
	cout<<find_maximum_subarray(s,0,n-1)<<endl;
	return 0;
}
