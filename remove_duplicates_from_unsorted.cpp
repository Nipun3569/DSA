#include <bits/stdc++.h> 

/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{   

    if(head==NULL){
        return NULL;
    }
    Node* curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        Node* temp=curr->next;
        Node* prev=curr;
        while(temp!=NULL){

          if (curr->data == temp->data) {

            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            temp=prev->next;
          }
          else{
          prev=temp;
          temp=temp->next;
          }
    
        }
        curr=curr->next;
    }
    return head;
}
