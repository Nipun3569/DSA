#include<iostream>

using namespace std;

void reverse(char name[], int n){
	int s=0;
	int e=n-1;
	
	while(s<=e){
		swap(name[s++],name[e--]);
	}
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
	reverse(name,len);
	cout<<"your name is "<<name<<endl;
	
}
