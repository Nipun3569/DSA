#include<iostream>

using namespace std;
//searching in sorted and rotated array
int pivotelement(int arr[],int n){
	int s=0;
	int e=n-1;
	
	int mid= s+(e-s)/2;
	
	while(s<e){
		if(arr[mid]>=arr[0]){
			s=mid+1;
		}
		else{
			e=mid;
		}
		mid= s+(e-s)/2;
	}
	return s;
}


int binarysearch(int arr[],int s,int e,int key){
    int start=s;
	int end=e;
	
	int mid=start+(end-start)/2;
	
	while(start<=end){
		
		if(arr[mid]==key){
			return mid;
		}
		
		else if(key>arr[mid]){
			start=mid+1;
		}
		
		else{
			end=mid-1;
		}
		mid=start+(end-start)/2;
	}	
	return -1;
}

int findposition(int arr[],int n,int k){
	int pivot=pivotelement(arr,n);
	//bs on second line
	if(k>arr[pivot]&&k<=arr[n-1]){
		return binarysearch(arr,pivot,n-1,k);
	}
	// bs on first line
	else{
		return binarysearch(arr,0,pivot-1,k);
	}
}
int main(){
	int arr[5]={8,10,17,1,3};
	
	cout<<findposition(arr,5,3);
	
		
}
