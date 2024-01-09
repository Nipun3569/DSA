#include<iostream>

using namespace std;
class node{
	public:
		int data;
		node* next;
		
		node(int data){
			this->data=data;
			this->next=NULL;
		}
		
		//destructor
		//memory free kradi
	 ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
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
	
	
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;
}

void deletenode(int position,node* &head){
	//deleting first or start node
	if(position==1){
		node* temp=head;
		head=head->next;
		//memory free kradi;
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
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}
void deleteNode(int position, node* & head) { 

    //deleting first or start node
    if(position == 1) {
        node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}
int main(){
	node* node1=new node(10);
	node* tail=node1;
	
	node* head=node1;
	print(head);
	
	insertAttail(tail,12);
	print(head);
	insertAttail(tail,15);
	
	print(head);
	
	insertAtposition(tail,head,4,50);
	print(head);
	
	//deletion
	deletenode(4,head);
	print(head);
}
