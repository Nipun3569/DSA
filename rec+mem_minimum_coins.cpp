int solveMem(vector<int> &num, int x, vector<int> &dp) {
    // Base cases
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return INT_MAX;
    }
    
    // Return already computed result
    if (dp[x] != -1) {
        return dp[x];
    }

    int mini = INT_MAX;
    
    // Compute the minimum elements for each element in the array
    for (int i = 0; i < num.size(); i++) {
        int ans = solveMem(num, x - num[i], dp);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    
    dp[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x) {
    vector<int> dp(x + 1, -1);
    int ans = solveMem(num, x, dp);
    
    if(ans==INT_MAX){
    return -1;
    }
    else{
        return ans;
    }
}
