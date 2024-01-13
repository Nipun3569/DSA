//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int findPosition(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
        //base case
        
        if(index>=n|| inorderStart>inorderEnd){
          return NULL;  
        }
        
        int element=pre[index++];
        
        Node* root=new Node(element);
        
        int position=findPosition(in,element,n);
        
        //recursive calls
        
        root->left=solve(in,pre,index,inorderStart,position-1,n);
        root->right=solve(in,pre,index,position+1,inorderEnd,n);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        
        Node* ans=solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends


//optimised code


//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    void createmapping(int in[],map<int,int> &NodeToIndex,int n){
        for(int i=0;i<n;i++){
            NodeToIndex[in[i]]=i;//inorder k element ko uske index k sath map krdo
        }
        
        
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &NodeToIndex){
        //base case
        
        if(index>=n|| inorderStart>inorderEnd){
          return NULL;  
        }
        
        int element=pre[index++];
        
        Node* root=new Node(element);
        
        //now we dont need to call function
        //int position=findPosition(in,element,n);
        int position=NodeToIndex[element];
        //recursive calls
        
        root->left=solve(in,pre,index,inorderStart,position-1,n,NodeToIndex);
        root->right=solve(in,pre,index,position+1,inorderEnd,n,NodeToIndex);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        map<int,int> NodeToIndex;
        createmapping(in,NodeToIndex,n);
        Node* ans=solve(in,pre,preOrderIndex,0,n-1,n,NodeToIndex);
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
