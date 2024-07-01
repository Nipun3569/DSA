int solveMem(int index,int operationNo, int k,vector<int>& prices,vector<vector<int>>& dp){
    if(index==prices.size()){
        return 0;
    }

    if(operationNo==2*k){
        return 0;
    }
    if(dp[index][operationNo]!=-1){
        return dp[index][operationNo];
    }
    int profit=0;
    if(operationNo%2==0){
        //buy allowed
        int buyKaro=-prices[index]+solve(index+1,operationNo+1,k,prices);
        int skipKaro=0+solve(index+1,operationNo,k,prices);
        profit=max(buyKaro,skipKaro);
    }else{
        int sellKaro=prices[index]+solve(index+1,operationNo+1,k,prices);
        int skipKaro=0+solve(index+1,operationNo,k,prices);
        profit=max(sellKaro,skipKaro);
    }
    return dp[index][operationNo]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        //n is for index so it is going from 0 to n that y taken n instead of n+1
        //col is for k so total transaction are 2*k
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return solveMem(0,0,k,prices,dp);
    }
};
