#include<iostream>

using namespace std;

int countdistinctways(int n){
	if(n<0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	
	int ans=countdistinctways(n-1)+countdistinctways(n-2);
	return ans;
}
int main(){
	int n;
	cin>>n;
	
	cout<<countdistinctways(n);
}
