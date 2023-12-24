#include<iostream>

using namespace std;

bool binarysearch(int *arr,int s,int e,int key){
	//base case
	//element not found
	if(s>e){
		return false;
	}
	//element found
	int mid=s+(e-s)/2;
	if(arr[mid]==key){
		return true;
	}
	
	
	if(arr[mid]<key){
		return binarysearch(arr,mid+1,e,key);
	}
	else{
		return binarysearch(arr,s,mid-1,key);
	}
}
int main(){
	int arr[6]={2,4,10,14,16};
	
	int size=6;
	int key=18;
	
	cout<<binarysearch(arr,0,size-1,key);
}
