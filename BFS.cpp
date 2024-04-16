#include <unordered_map>
#include <queue>
#include <list>
#include <set>


void prepareAdjList(unordered_map<int, list<int>> &adjlist, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
       
       //using set for sorted order
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

void printadjList(unordered_map<int, list<int>>& adjlist){
    for(auto i:adjlist){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<" ";
        }cout<<endl;
    }
}
void bfs(unordered_map<int, list<int>> &adjlist, unordered_map<int,bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i : adjlist[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    unordered_map<int, set<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjlist, adj);
    //printadjList(adjlist);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adjlist, visited, ans, i);
        }
    }

    return ans;
}
