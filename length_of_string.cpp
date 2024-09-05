#include<iostream>

using namespace std;
//we dont need to pass length of array in character arrays
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
	
	cout<<get_length(name);
}
