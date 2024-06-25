#include<iostream>

using namespace std;

class stack{
	public:
		int *arr;
		int top;
		int size;
		
		stack(int size){
			this->size=size;
			top=-1;
			arr=new int[size];
		}
		
		void push(int element){
			if(size-top>1){
				top++;
				arr[top]=element;
			}else{
				cout<<"stack overflow"<<endl;
			}
		}
		
		void pop(){
			if(top>=0){
				top--;
			}else{
				cout<<"underflow"<<endl;
			}
		}
};
int main(){
	
	
}
