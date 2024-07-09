

// } Driver Code Ends
//User function Template for C

/*
// Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};
 
// function to create a queue of given capacity
struct Queue* createQueue(unsigned capacity);
 
// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue);
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
void enqueue(struct Queue* queue,struct Node* item);

// Function to remove an item from queue.
void dequeue(struct Queue* queue);

// Function to get front of queue
struct Node* front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);

// Utility function to create a new Tree Node
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
*/


//Function to find the height of a binary tree.

int max(struct Node*left,struct Node* right){
    if(left>right){
        return left;
    }
    else{
        return right;
    }
}
int height(struct Node* node)
{
    //base case
    
    if(node==NULL){
        return 0;
    }
    
    int left=height(node->left);
    int right=height(node->right);
    
    int ans= max(left,right)+1;
    
    return ans;
    
    
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        char str[100000];
        scanf("%[^\n]%*c", str);
        struct Node* root = buildTree(str);
        printf("%d\n",height(root));
    }
    return 0;
}
// } Driver Code Ends
