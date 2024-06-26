int lengthOfLongestAP(int A[], int n) {
        if (n <= 2) {
            return n;
        }
        
        int ans = 0;
        unordered_map<int, int> dp[n]; // dp array of unordered maps
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                int cnt = 1;
                
                // Check if an AP ending at j with difference diff already exists
                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
};
