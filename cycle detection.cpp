#using bfs
#include<unordered_map>
#include<queue>
#include<list>
bool isCyclicBFS(int src,unordered_map<int,bool> &visited,unordered_map<int , list<int>> &adj){

    unordered_map<int,int> parent;

    parent[src]=-1;
    visited[src]=1;
    
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front=q.front();

        q.pop();
       
       //front k saare neighbor nikaal liye
        for(auto neighbor:adj[front]){
       
       if(visited[neighbor]==true && neighbor!=parent[front]){
           return true;
       }
       else if(!visited[neighbor]){
           q.push(neighbor);
           visited[neighbor]=true;
           parent[neighbor]=front;
       }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    //create adjacency list
   
   unordered_map<int , list<int>> adj;
    for(int i=0;i<m;i++){
    
    int u=edges[i][0];
    int v=edges[i][1];

    adj[u].push_back(v);

    adj[v].push_back(u);
    }

    //to handle components
   unordered_map<int,bool> vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bool ans=isCyclicBFS(i,vis,adj);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";
}







#using dfs

bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int , list<int>> &adj){
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){

            bool cycledetected=isCyclicDFS(neighbour, node, visited, adj);

            if(cycledetected){
                return true;

            }

        }
        else if(neighbour!=parent){
       //cycle present
       return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    //create adjacency list
   
   unordered_map<int , list<int>> adj;
    for(int i=0;i<m;i++){
    
    int u=edges[i][0];
    int v=edges[i][1];

    adj[u].push_back(v);

    adj[v].push_back(u);
    }

    //to handle components
   unordered_map<int,bool> vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bool ans=isCyclicDFS(i,-1,vis,adj);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";
}
