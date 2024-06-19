int solveMem(vector<int>& obstacles, int currlane, int pos, vector<vector<int>>& dp) {
        // base case
        int n = obstacles.size();
        if (pos == n - 1) {
            return 0; 
        }

        if (dp[currlane][pos] != -1) {
            return dp[currlane][pos];
        }

        if (pos + 1 < n && obstacles[pos + 1] != currlane) {
            return solveMem(obstacles, currlane, pos + 1, dp);
        } else {
            // sideways jump
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (currlane != i && obstacles[pos] != i) {
                    ans = min(ans, 1 + solveMem(obstacles, i, pos, dp)); // 1 jump done
                }
            }
            dp[currlane][pos] = ans;
            return dp[currlane][pos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4,vector<int> (obstacles.size(),-1));
        return solveMem( obstacles, 2,0,dp);
    }
};
