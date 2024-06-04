#include<iostream>

using namespace std;

//square root using binary search

long long int square_root(int x){
	int s=0;
	int e=x;
	
	long long int mid=s+(e-s)/2;
	long long int ans=-1;
	while(s<=e){
		long long  int square=mid*mid;
		if(square==x){
			return mid;
		}
		
		else if(square<x){
			ans=mid;
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
	cout<<square_root(25);
}
