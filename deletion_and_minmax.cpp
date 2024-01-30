#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    //base case
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        //insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else {
        //insert in left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node* minValue(Node* root){
	Node* temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

Node* maxValue(Node* root){
	Node* temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}
void takeInput(Node*& root) { // Pass root by reference
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

Node* deleteFromBST(Node* root,int value){
	//base case
	if(root==NULL){
		return root;
	}
	
	if(root->data==value){
		//delete logic
		
		//0 child
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		
		//1 child
		//left child
		if(root->left!=NULL && root->right==NULL){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		
		//right child
		if(root->left==NULL && root->right!=NULL){
			Node* temp=root->right;
			delete root;
			return temp;
		}
		
		
		//2 child
		if(root->left!=NULL && root->right!=NULL){
			//do any left or right
			int mini=minValue=(root->right)->data;
			
			//copy 
			root->data=mini;
			root->right=deleteFromBST(root->right,mini);
		}
	}
	else if(root->data>value){
		root->left=(root->left,value);
		return root->left;
	}
	else{
		root->right=(root->right,value);
		return root->right;
	}
}
int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to stop):" << endl;

    takeInput(root);

    cout<<"printing the bst"<<endl;
    
    levelOrderTraversal(root);
    
    cout<<"minimum value"<<minValue(root)->data<<endl;
    cout<<"maximum value"<<maxValue(root)->data<<endl;
}
