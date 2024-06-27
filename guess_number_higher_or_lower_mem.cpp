int solveMem(int start,int end,vector<vector<int>> &dp){
   if(start>=end){
    return 0;
   }
   int maxi=INT_MAX;
   if(dp[start][end]!=-1){
    return dp[start][end];
   }
   for(int i=start;i<=end;i++){
    maxi=min(maxi,i+max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
   }
   return dp[start][end]=maxi;
}
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solveMem(1,n,dp);    
    }
};
