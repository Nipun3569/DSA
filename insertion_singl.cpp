#include<iostream>

using namespace std;

class node{
	public:
		int  data;
		node *next;
		node(int data){
			this->data=data;
			this->next=NULL;
		}
};
//d is data
void insertAthead(node* &head,int d){
	//creating new node
	node * temp=new node(d);
	temp->next=head;
	head=temp;
}

//traversing linked list

void print(node* &head){
	node* temp=head;//ek pointer bnaya jo head pe point krra hai
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	 cout<<endl;
}
void insertAttail(node* &tail,int d){
	node* temp=new node(d);
	
	tail->next=temp;
	tail=tail->next;
}
void insertAtposition(node* & tail,node* &head,int position,int d){
	if(position==1){
		insertAthead(head,d);
		return;
	}
	
	node* nodetoinsert=new node(d);
	node* temp=head;
	int cnt=1;
	while(cnt!=position-1){
		temp=temp->next;
		cnt++;
	}
	
	//inserting at last position
	if(temp->next==NULL){
		insertAttail(tail,d);
	}
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;
}
int main(){
	//heap mei create karenge
	node* node1=new node(10);
	node* tail=node1;
	//cout<<node1->data<<endl;
	//cout<<node1->next<<endl;
	
	node* head=node1;
	print(head);
	//insertAthead(head,12);
	insertAttail(tail,12);
	print(head);
	insertAttail(tail,15);

	print(head);
	
	insertAtposition(tail,head,4,50);//cant insert at 1st position so if case lagaya
	//when position is everything works fine but tail doesnt get updated so one more condition
	print(head);
}
