#approach 1

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode *root,vector <int>&in){
    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}

vector<int> mergearrays(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size()+b.size());

    int i=0,j=0,k=0;

    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }

    }
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }

    return ans;

}
TreeNode* inorderToBST(int s, int e, vector<int> &in) {
    // base case
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    TreeNode* root = new TreeNode(in[mid]);

    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{
    // step1: store inorder
    
    vector<int> bst1,bst2;

    inorder(root1,bst1);
    inorder(root2,bst2);

    //merge two sorted arrays

    vector<int> Mergedarray=mergearrays(bst1,bst2);
   
   //inorder to bst
   int s=0;
   int e=Mergedarray.size()-1;
   return inorderToBST(s,e,Mergedarray);

}


#approach 2

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode *root,vector <int>&in){
    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}


void convertIntoSortedDLL(TreeNode* root,TreeNode* &head){
  //base case 
  if(root==NULL){
      return NULL;
  }
  convertIntoSortedDLL(root->right,head)

  root->right=head;
  if(head!=NULL){
      head->left=root;
  }
   head=root;

   convertIntoSortedDLL(root->left,head)



}

TreeNode* mergeLL(TreeNode* head1,TreeNode* head2){
    TreeNode* head=NULL;
    TreeNode* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                //insert at end krna hai
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;  
                head2=head2->right;
            }
        }
    }

    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }

     while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
}


vector<int> mergearrays(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size()+b.size());

    int i=0,j=0,k=0;

    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }

    }
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }

    return ans;

}
int countNodes(TreeNode* &head){
    int cnt=0;
    TreeNode* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
TreeNode *sortedLLtoBST(TreeNode *&head, int n){
   //base case
   if(n<=0||head==NULL){
       return NULL;
   }

   TreeNode* left=sortedLLtoBST(head, n/2);
   
   TreeNode* root=head;

   root->left=left;
   head=head->next;
   //roght subtree
   TreeNode* right=sortedLLtoBST(head, n-n/2-1);


return root;

    
}

TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{   //step1:convert BST into sorted LL inplace
    TreeNode* head1=NULL;
    convertIntoSortedDLL(root1, head1)
    head1->left=NULL;

    TreeNode* head2=NULL;
    convertIntoSortedDLL(root2, head2)
    head2->left=NULL;

   
   //step2:Merge sorted LL

   TreeNode* head=mergeLL(head1, head2);

   //step3:convert sorted ll into bst

   return sortedLLtoBST(head, countNodes(head));
   



}
