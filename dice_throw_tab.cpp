long long solveTab(int d,int f,int t){
        vector<vector<long long>> dp(d+1,vector<long long>(t+1,0));
        //after analysing base case
        dp[0][0]=1;
        
        for(int dice=1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                
                long long ans=0;
        for(int i=1;i<=f;i++){
            if(target-i>=0){
            ans=ans+dp[dice-1][target-i];
        }
        }
        dp[dice][target]=ans;
            }
        }
        
        return dp[d][t];
        
        
        
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        
        return solveTab(N,M,X);
    }
};
