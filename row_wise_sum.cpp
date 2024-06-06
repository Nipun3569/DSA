#include<iostream>

using namespace std;

void printSum(int arr[][3],int row,int col){
	cout<<"printing sum "<<endl;
	for(int i=0;i<3;i++){
		int sum=0;
		for(int j=0;j<3;j++){
			sum+=arr[i][j];
		}
		cout<<sum<<" ";
		cout<<endl;
	}
}

int largestrowsum(int arr[][3],int row,int col){
	int maxi=INT_MIN;
	int rowIndex=-1;
	for(int i=0;i<3;i++){
		int sum=0;
		for(int j=0;j<3;j++){
			sum+=arr[i][j];
		}
		if(sum>maxi){
			maxi=sum;
		rowIndex=row;
		}
		
	}
	cout<<"maximum sum is"<<maxi<<endl;
	return rowIndex;
} 
int main(){
	int arr[3][3];
	cout<<"enter the elemnets"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	
	cout<<"printing the array elements"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}
	
	printSum(arr,3,4);
	int ans=largestrowsum(arr,3,3);
	cout<<"lagest sum is on index "<<ans;
}
