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
#include<queue>
#include<vector>
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
}

Node* mergeKLists(vector<Node*>& listArray) {

    priority_queue<Node*, vector<Node*>, compare> minHeap;
    int k = listArray.size();

    if (k == 0) {
        return NULL;
    }

    // Step 1: Push the heads of all lists into the min heap
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;
    
    // Step 2: Merge the lists using min heap
    while (!minHeap.empty()) {
        Node* top = minHeap.top();
        minHeap.pop();
        
        // If the popped node has a next, push it into the heap
        if (top->next != NULL) {
            minHeap.push(top->next);
        }
        
        // If the result list is empty, assign head to top
        if (head == NULL) {
            head = top;
            tail = top;
        } else {
            // Otherwise, insert at the end of the result list
            tail->next = top;
            tail = top;
        }
    }
    
    return head;
}
