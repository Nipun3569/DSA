#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
	
	//creation
	unordered_map<string,int> m;
	
	//insertion
	//one way
	pair<string,int> p=make_pair("babbar",3);
	m.insert(p);
	
	//second way
	
	pair<string,int> pair2("love",2);
	m.insert(pair2);
	
	
	//thirdway
	m["mera"]=1;
	//updation
	m["mera"]=2;
	
	//search
	
	cout<<m["mera"]<<endl;
	cout<<m.at("babbar")<<endl;
	
	cout<<m["unknownkey"]<<endl;//makes entry
	cout<<m.at("unknownkey")<<endl;//return 0 now
	
	//size
	cout<<m.size()<<endl;
	
	//to check presence
	cout<<m.count("bro")<<endl;
	cout<<m.count("love")<<endl;
	
	//erase
	m.erase("love");
	cout<<m.size()<<endl;
	
	
	for(auto i:m){
		cout<<i.first<<" "<<i.second<<endl;
	}
	
	//iterator
	unordered_map<string,int> ::iterator it=m.begin();
	
	while(it!=m.end()){
		cout<<it->first<<" "<<it->second<<endl;
		it++;
	}
	
	
	
}
