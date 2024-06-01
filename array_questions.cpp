#include<iostream>

using namespace std;

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//swapping alternate numbers of array
/*void swapAlter(int arr[],int n){
	int start=0;
	int end=1;
	
	while(end<=n-1){
		swap(arr[start],arr[end]);
		start=start+2;
		end=end+2;
	}
}*/


//finding unique element in the array

int findUnique(int arr[],int n){
	
	int ans=0;
	
	for(int i=0;i<n;i++){
		ans=ans^arr[i];
	}
	return ans;
}
//finding duplicate elements of array
int findDuplicate(int arr[],int n){
	int ans=0;
	//XOR all array element
	for(int i=0;i<n;i++){
		ans=ans^arr[i];
	}
	//XOR[1,n-1]
	for(int i=0;i<n;i++){
		ans=ans^i;
	}
	return ans;
}
//finding intersection of elements of two arrays

int intersection(int arr[],int brr[],int n,int m){
	
	int ans;
	for(int i=0;i<n;i++){
		int element=arr[i];
		
		for(int j=0;j<m;j++){
			if(element==arr[j]){
				ans=element;
				//update
				arr[j]=INT_MIN;
				break;
			}
		}
	}
	return ans;

}
int main(){
	//int arr[5]={2,3,5,6,7};
	//int arr[7]={3,7,2,2,7,3,4};
	//int arr[7]={1,2,3,4,5,6,6};
	
	//swapAlter(arr,5);
	//printArray(arr,7);
	
	//cout<<findUnique(arr,7);
	//cout<<findDuplicate(arr,7);
	
	int arr[3]={1,2,3};
	int brr[2]={3,4};
	
	cout<<intersection(arr,brr,3,2);
}
