class Solution {
  public:
  
 //create mapping
 //retrn target node
    Node* createParentmapping(Node* root,map<Node*,Node*> &nodeToparent,int target){
        Node* result=NULL;
        
        //level order traversal
        queue<Node*> q;
        nodeToparent[root]=NULL;
        
        q.push(root);
        while(!q.empty()){
            Node* frontNode=q.front();
            
            q.pop();
            
            if(frontNode->data==target){
                return frontNode;
            }
            
            if(frontNode->left){
                nodeToparent[frontNode->left]=frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right){
                nodeToparent[frontNode->right]=frontNode;
                q.push(frontNode->right);
            }
            
        }
        
        return NULL;
    }
    
    int burnTree(Node* root,map<Node*,Node*> &nodeToparent){
        map<Node*,bool> visited;
        queue<Node*> q;
        int ans=0;
        q.push(root);
        visited[root]=true;
        
        while(!q.empty()){
            //to check wheher addition happened or not
            
            bool flag =0;
            int size=q.size();
            
            for(int i=0;i<size;i++){
                //processing neighbouring nodes
                
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=true;
                }
                
                if(front->right && !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=true;
                }
                
                if(nodeToparent[front]!=NULL && !visited[nodeToparent[front]]){
                    flag =1;
                    q.push(nodeToparent[front]);
                    visited[nodeToparent[front]]=true;
                }
               
            }
         if(flag==1){
                    ans++;
                }
            
        }
        
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // algo
        //step 1 create node to parent mapping
        //step 2 find target node
        //step3 burn the tree in min time
        
        
        map<Node*,Node*> nodeToparent;
        Node* targetNode=createParentmapping(root,nodeToparent,target);
        
         int ans=burnTree(targetNode,nodeToparent);
        return ans;
        
        
    }
};
