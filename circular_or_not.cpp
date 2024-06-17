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
void insertnode(node* & tail,int element,int d){

	if(tail==NULL){
		//empty list
		node* temp=new node(d);
		tail=temp;
		temp->next=temp;
	}
	else{
		//non empty list
			//assuming that the element is present in the list
		node * curr=tail;
		while(curr->data!=element){
			curr=curr->next;
		}
		//element found -> current is representing element vala node
		node * temp=new node(d);
		temp->next=curr->next;
		curr->next=temp;
	}
}

void print(node* & tail){
	node *temp=tail;
	if(tail==NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	do{
		cout<<tail->data<<" ";
		tail=tail->next;
	}while(tail!=temp);
	cout<<endl;
}
void deletenode(int value,node* & tail){//we pass value now position already done

     //empty list
     if(tail==NULL){
     	cout<<"list is empty"<<endl;
     	return;
	 }
	
	 
	 else{
	 	//non empty
	 	//assuming that value is present in linked list
	 	node* prev=tail;
	 	node* curr=prev->next;
	 	while(curr->data!=value){
	 		prev=curr;
	 		curr=curr->next;
		 }
		 prev->next=curr->next;
		 //for 1 node linked list
		 if(curr==prev){
		 	tail=NULL;
		 }
		 //>=2 node linked list
		 if(tail==curr){
		 	tail=prev;
		 }
		 curr->next=NULL;
		 delete curr;
	 }
	
}

bool iscircularlist(node* &head){

   //empty list
   if(head==NULL){
   	return 1;
   }	
   
   node* temp=head->next;
   
   while(temp!=NULL&&temp!=head){
   	temp=temp->next;
   }
   if(temp==head){
   	return 1;
   }
   if(temp==NULL){
   	return 0;
   }
}
int main(){
    	node*tail=NULL;
    	insertnode(tail,5,3);
    	print(tail);
    	
    	insertnode(tail,3,5);
    	print(tail);
    	
    		
    	insertnode(tail,5,7);
    	print(tail);
    	
    	cout<<iscircularlist(tail);
}
