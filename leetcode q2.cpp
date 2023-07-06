//number of 1's
#include<iostream>

using namespace std;

int main(){
	int n,count=0;
	cout<<"enter number"<<endl;
	cin>>n;
	
	while(n!=0){
		//checking last bit
		
		if(n&1){
			count++;
		}
		
		n=n>>1;
	}
	
	cout<<count;
	
}
