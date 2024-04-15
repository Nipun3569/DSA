vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    
    vector<int> ans[n];
   //ans array will store all adjacent nodes corresponding on indexes
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

       //u k liye v pushback krdo
        ans[u].push_back(v);

        ans[v].push_back(u);//since it is undirected


    }



    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){
        adj[i].push_back(i);//referring to output format

        //uske baad neighbour daaldo

        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}
