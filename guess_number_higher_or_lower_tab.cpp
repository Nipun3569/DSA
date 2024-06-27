 int solveTab(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {
                if (start == end) {
                    continue;
                } else {
                    int maxi = INT_MAX;
                    for (int i = start; i <= end; i++) {
                        int cost = i + max(dp[start][i - 1], dp[i + 1][end]);
                        //here
                 //i+1 so hum n se aage jane ki koshish kar rahe hai so n+2 , n+1 ki jgah
                        maxi = min(maxi, cost);
                    }
                    dp[start][end] = maxi;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solveTab(n);    
    }
};
