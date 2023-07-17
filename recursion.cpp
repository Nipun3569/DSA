#include<iostream>

using namespace std;

int factorial(int n){
	//base case
	
	if(n==0){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}
int powerof2(int n){
	if(n==0){
		return 1;
	}
	else{
		return 2*powerof2(n-1);
	}
}

void printcounting(int n){
	if(n==0){
		return;
	}
	
		return printcounting(n-1);
		cout<<n<<" ";
		//return printcounting(n-1);
	
}
int main(){
	int n;
	
	cin>>n; 
	
	
	/*
	int ans=factorial(n);
	cout<<ans;*/
	
	/*int ans=powerof2(n);
	cout<<ans;
*/
    printcounting(n);
}
