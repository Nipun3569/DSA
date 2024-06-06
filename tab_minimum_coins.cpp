int solveTab(vector<int> &num, int x) {
    vector<int> dp(x + 1, INT_MAX); // Initialize dp array with INT_MAX
    dp[0] = 0; // Base case: 0 amount requires 0 elements

    for (int i = 1; i <= x; i++) {
        // Try to solve for every amount from 1 to x
        for (int j = 0; j < num.size(); j++) {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    // If dp[x] is still INT_MAX, it means no solution was found
    if(dp[x]==INT_MAX){
        return -1;
    }else{
        return dp[x];
    }
}

int minimumElements(vector<int> &num, int x) {
    return solveTab(num, x);
}
