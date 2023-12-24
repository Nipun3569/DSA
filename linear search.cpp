#include<iostream>
using namespace std;

int linear(int *arr,int n,int key){
	if(n==0){
		return 0;
	}
	
	if(arr[n-1]==key){
		return (n-1);
	}
	
	return linear(arr,n-1,key);
	
}

int main(){
	int arr[5]={5,2,4,9,8};
	cout<<linear(arr,5,0);
}
