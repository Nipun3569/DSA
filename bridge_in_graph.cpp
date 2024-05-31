#include <unordered_map>
#include <list>
#include <vector>


void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result,
         unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!vis[nbr]) {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // Check for bridge
            if (low[nbr] > disc[node]) {
                result.push_back({node, nbr});
            }
        } else {
            // Back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    // Initialize visited map
    for (int i = 0; i < v; i++) {
        vis[i] = false;
    }

    // DFS
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            int parent = -1;
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}

