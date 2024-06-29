int solveMem(int index,int buy,vector<int> &prices,vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
       int profit=0;
        if(buy){
            profit=max((-prices[index]+solveMem(index+1,0,prices,dp)),(0+solveMem(index+1,1,prices,dp)) );

        }
        else{
            profit=max((+prices[index]+solveMem(index+1,1,prices,dp)),(0+solveMem(index+1,0,prices,dp)));
        }
        dp[index][buy]=profit;
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solveMem(0,1,prices,dp);

    }
};
