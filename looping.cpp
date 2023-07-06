#include<iostream>

using namespace std;

int main(){
	int n;
	//sum of even numbers between 1 to n
	/*cout<<"enter the digit upto which you want sum of even numbers"<<endl;
	cin>>n;
	
	int sum=0;
	for(int i=2;i<=n;i+=2){
		sum+=i;
	}
	cout<<sum;*/
	
	
	cout<<"enter number"<<endl;
	
	cin>>n;
	int i=2;
	while(i<n){
	
	if(n%i==0){
		cout<<"not prime"<<endl;
		break;
	}
	else{
		cout<<"prime"<<endl;
		break;
	}
	i=i+1;
}
}
