int solve3(vector<int> &cost,int n){
        //base case
        //step 1 creation
        vector<int> dp(n+1);
        //step 2 base case analyse
        dp[0]=cost[0];
        dp[1]=cost[1];

        //3rd step
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return  min(dp[n-1],dp[n-2]);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        

        //int n=cost.size();
        //int ans=min(solve(cost,n-1),solve(cost,n-2));

        //return ans;


       // int n=cost.size();
       //step 1
        //vector<int> dp(n+1,-1);
        //int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        //return ans;

        int n=cost.size();

        return solve3(cost,n);
    }
};
