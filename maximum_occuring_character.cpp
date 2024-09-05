#include<iostream>

using namespace std;

char getMaxoccur(string s){
	int arr[26]={0};
	//create an array of count of characters
	for(int i=0;i<s.length();i++){
		char ch=s[i];
		//lowercase
		int number;

			number =ch-'a';
		arr[number]++;
	}
	
	int maxi=INT_MIN,ans=0;
	//find maximum occurence character
	for(int i=0;i<26;i++){//saare characters k liye loop chlana hai
		if(maxi<arr[i]){
		 ans=i;
		maxi=arr[i];	
		} 
	}
	
	char finalAns='a'+ans;
	return finalAns;
}
int main(){
	string s;
	cin>>s;
	
	cout<<getMaxoccur(s);
}
