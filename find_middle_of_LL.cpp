/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
int getlength(Node* head){
    int cnt=0;
    Node *temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
        
    }
    return cnt;
}

Node* getmiddle(Node* head){
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL){
        fast=fast->next;
        //dusra kadam
        if(fast!=NULL){
            fast=fast->next;
        }

        slow=slow->next;

    }
    return slow;
}
Node *findMiddle(Node *head) {
   /* int length=getlength(head);
    int ans=length/2;

    Node* temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;*/

    return getmiddle(head);
}

