vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Initialize the distance to all vertices as infinity
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative-weight cycles
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    // If there is a negative weight cycle, return an empty vector
    if (hasNegativeCycle) {
        return {};
    }

    // Return the distance array
    return dist;

}
