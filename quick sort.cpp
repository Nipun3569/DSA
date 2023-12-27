#include<iostream>

using namespace std;
void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int partition(int arr[],int s,int e){
	int pivot=arr[s];
	
	int cnt=0;
	
	for(int i=s+1;i<=e;i++){
		if(arr[i]<=pivot){
			cnt++;
		}
	}
	//place pivot at right position
	int pivotIndex=s+cnt;
	
	swap(arr[pivotIndex],arr[s]);
	
	//left and right wala part sambhal lete hai
	
	int i=s;
	int j=e;
	
	while(i<pivotIndex&&j>pivotIndex){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		
		if(i<pivotIndex&&j>pivotIndex){
			swap(arr[i++],arr[j--]);
		}
	}
	
	return pivotIndex;
	
}
void quicksort(int arr[],int s,int e){
	//base case
	if(s>=e){
		return ;
	}
	
	// partition karenge
	
	int p=partition(arr,s,e);
	//left sub array sort kro
	quicksort(arr,s,p-1);
	//right sub array sort karo
	quicksort(arr,p+1,e);
}
int main(){
	int arr[5]={2,4,1,6,9};
	
	int n=5;
	printarray(arr,n);
	quicksort(arr,0,n-1);
	printarray(arr,n);
}
