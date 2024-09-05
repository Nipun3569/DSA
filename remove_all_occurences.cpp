#include<iostream>

using namespace std;

string remove_substring(string s,string part){
	while(s.length()!=0 && s.find(part)<s.length()){//go to c++site gor working of find
		s.erase(s.find(part),part.length());
	}
	return s;
}
int main(){
	string s="daaabcbaabcbc";
	string part="abc";
	
	cout<<remove_substring(s,part);
}
