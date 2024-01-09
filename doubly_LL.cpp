#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
		~node(){
			int val=this->data;
			if(next!=NULL){
				delete next;
				next=NULL;
			}
			cout<<"memory free for node with data "<<val<<endl;
		}
};
void print(node* & head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
//finding length of linked list
int getlength(node * head){
	node* temp=head;
	int cnt=0;
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
void insertAthead(node* &tail,node* &head,int d){
	//emptylist
	if(head==NULL){
    node *temp=new node(d);
	head=temp;		
	tail=temp;
	}
	else{
	
	node* temp=new node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
}
void insertAttail(node* & head,node* & tail,int d){
	if(tail==NULL){
    node* temp=new node(d);
	tail=temp;		
	head=temp;
	}
	else{
	
	node* temp=new node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
}

void insertAtPosition(node* & tail, node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAthead(tail,head, d);
        return;
    }

    node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
    	
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAttail(head,tail, d);
        return ;
    }

    //creating a node for d
    node* nodeToInsert = new node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deletenode(int position,node* &head){
	//deleting first or start node
	if(position==1){
		node* temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	//deleting any middle or last node
	else{
		node* curr=head;
		node* prev=NULL;
		int cnt=1;
		while(cnt<position){
			prev=curr;
			curr=curr->next;
		cnt++;
		}
		curr->prev=NULL;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}
int main(){
	
	//but if we dont have any starting node then there will be problem
	//same do with singly linked list
	node * node1=new node(10);
	//node* head=node1;
	//node* tail=node1;
	node*head=NULL;
	node*tail=NULL;
	print(head);
	//cout<<getlength(head);
	insertAthead(tail,head,15);
	print(head);
	insertAthead(tail,head,13);
	print(head);
	insertAthead(tail,head,8);
	print(head);
	insertAttail(head,tail,50);
	print(head);
	insertAtPosition(tail,head,4,100);
	print(head);
	deletenode(5,head);
	print(head);
}
