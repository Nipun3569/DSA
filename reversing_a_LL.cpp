#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
void reverse(LinkedListNode<int> *&head,LinkedListNode<int> *curr,
LinkedListNode<int> *prev){
     //base case
     if(curr==NULL){
         head=prev;
         return;
     }

     //1 case solv e kiya
     LinkedListNode<int> *forward=curr->next;
     reverse(head,forward,curr);
     curr->next=prev;
}
//it will return head of the reverse list
LinkedListNode<int> *reverse1(LinkedListNode<int> *&head){
    //base case
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    LinkedListNode<int> *chotahead=reverse1(head->next);

    head->next->next=head;
    head->next=NULL;
    return chotahead;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{ 
    return reverse1(head);
    
    
    
    /*
    if(head==NULL||head->next==NULL){
        return head;
    }
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;*/
}
