#include <bits/stdc++.h> 

class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row,int col){
        this->data=data;
        i=row;
        j=col;

    }
};
//syntax
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    //compare likhna pdega kyuki custom bnaya hai
    priority_queue<node*, vector<node*>, compare> minHeap;  

    //step1 saare arrays k first element insert krne h

    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0], i,0);
        minHeap.push(temp);
    }

    vector<int> ans;
    //step 2
    while(minHeap.size()>0){
    node* tmp=minHeap.top();
    ans.push_back(tmp->data);
    minHeap.pop();

    int i=tmp->i;
    int j=tmp->j;

    if(j+1< kArrays[i].size()){
        node* next=new node(kArrays[i][j+1],i,j+1);
        minHeap.push(next);
    }

    }
    return ans;
}
