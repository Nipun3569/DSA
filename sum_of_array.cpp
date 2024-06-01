#include<iostream>
#include<vector>
using namespace std;

vector<int> sum_of_array(int arr1[],int n,int arr2[],int m){
	int i=n-1;
	int j=m-1;//last index
	vector<int> ans;
	int carry=0;
	
	while(i>=0&&j>=0){
		int val1=arr1[i];
		int val2=arr2[j];
		
		int sum=val1+val2+carry;
		
		carry=sum/10;
		sum=sum%10;
		
		ans.push_back(sum);
		i--;
		j--;
	}
	
	//first case
	while(i>=0){
		int sum=arr1[i]+carry;
		carry=sum/10;
		sum=sum%10;
		
		ans.push_back(sum);
		i--;
	}
	
	//second case
	
	while(j>=0){
		int sum=arr2[j]+carry;
		carry=sum/10;
		sum=sum%10;
		
		ans.push_back(sum);
		j--;
	}
	
	//third case carry bacha hua hai
	
	while(carry!=0){
		int sum=carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
	}
	
	return ans;
}
int main(){
	int arr1[3]={9,9,9};
	int arr2[3]={9,9,9};
	
	cout<<sum_of_array(arr1,3,arr2,3);
}
