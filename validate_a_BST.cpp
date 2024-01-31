#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool isBST(BinaryTreeNode<int> *root,int minvalue,int maxvalue){
     
     //base case
     if(root==NULL){
         return true;
     }

     if(root->data>=minvalue && root->data<=maxvalue){
         bool left=isBST(root->left,minvalue,root->data);
          bool right=isBST(root->right,root->data,maxvalue);

          return left&&right;
     }
     else{
         return false;
     }
     
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);
}
