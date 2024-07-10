class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
    bool isBalanced(Node *root)
    {   if(root==NULL){
        return 1;
    }
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        bool difference=abs(height(root->left)-height(root->right))<=1;
        
        if(left&& right && difference){
            return 1;
        }else{
            return 0;
        }
    }
};
