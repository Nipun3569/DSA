#include<iostream>

using namespace std;

int firstoccur(int arr[],int size,int key){
	
	int s=0;
	int e=size-1;
	int ans=-1;
	int mid=s+(e-s)/2;
	
	while(s<=e){
		if(arr[mid]==key){
			ans=mid;
			e=mid-1; 
		}
		
		else if(key>arr[mid]){
			s=mid+1;
		}
		
		else{
			e=mid-1;
		}
	 mid=s+(e-s)/2;
	}
	return ans;
}

int Lastoccur(int arr[],int size,int key){
	
	int s=0;
	int e=size-1;
	int ans=-1;
	int mid=s+(e-s)/2;
	
	while(s<=e){
		if(arr[mid]==key){
			ans=mid;
			s=mid+1; 
		}
		
		else if(key>arr[mid]){
			s=mid+1;
		}
		
		else{
			e=mid-1;
		}
	 mid=s+(e-s)/2;
	}
	return ans;
}
int main(){
	
	int even[5]={1,2,3,3,5};
	
	cout<<"first occurence of 3 is at index "<<firstoccur(even,5,3)<<endl;
	cout<<"last occurence of 3 is at index "<<Lastoccur(even,5,3);
}
