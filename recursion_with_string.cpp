#include<iostream>

using namespace std;

void reverse(string& str,int i,int j){
	if(i>j){
		return;
	}
	
	swap(str[i],str[j]);
	i++;
	j--;
	reverse(str,i,j);
}

bool checkpalindrom(string str,int i,int j){
	/*if(str[i]!=str[j]){
		return false;
	}
	
	if(str[i]==str[j]){
		i++;
		j--; 
		checkpalindrom(str,i,j);
	}
	if(i>j){
		return true;
	}                   OR*/
	
	
	if(i>j){
		return true;
	}
	
	if(str[i]!=str[j]){
		return false;
	}
	else{
		checkpalindrom(str,i+1,j-1);
	}
	
}

int power(int a,int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	//recursive call
	int ans=power(a,b/2);
	//if b is even
	if(b%2==0){
		 return ans*ans;//a ki power b/2 * a ki power b/2
	}
	// if b is odd
	else{
		return a*ans*ans;
	}
	
}
int main(){
	
	//string s="naman";
	
	//reverse(s,0,s.length()-1);
	//cout<<s;
  //cout<<checkpalindrom(s,0,s.length()-1);
  
  int a,b;
  cin>>a>>b;
  
  cout<<power(a,b);
}
