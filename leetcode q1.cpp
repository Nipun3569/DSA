//subtract the sum and product of digits of an integer
#include<iostream>

using namespace std;

int main(){
	int n,prod=1,sum=0;
	cout<<"enter number"<<endl;
	cin>>n;
	
	while(n!=0){
		int digit=n%10;
		prod=prod*digit;
		sum=sum+digit;
		n=n/10;
		
	}
	int answer=prod-sum;
	cout<<answer;
}
