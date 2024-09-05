#include<iostream>

using namespace std;
char toLowerCase(char ch){
	if(ch>='a'&&ch<='z'){
		return ch;
	}
	else{
		char temp=ch-'A'+'a';
	return temp;
	}
}
bool check_palindrome(char a[],int n){
	int s=0;
	int e=n-1;
	
	while(s<=e){
		if(toLowerCase(a[s])!=toLowerCase(a[e])){
			return 0;
		}
		else{
			s++;
			e--;
		}
	}
	return 1;
}

int get_length(char name[]){
	int count=0;
	for(int i=0;name[i]!='\0';i++){
		count++;
	}
	return count;
}
int main(){
     char name[20];
	
	cout<<"enter you name"<<endl;
	cin>>name;
	
	int len=get_length(name);
	cout<<"is it a palindrome-> "<<check_palindrome(name,len);
	
	
}
