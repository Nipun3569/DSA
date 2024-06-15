int solveTab(int n){
	    vector<int> dp(n+1,INT_MAX);
	    //since minimum number nikaal rhe hai so INT_MAX daalenge
	    
	    dp[0]=0;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j*j<=n;j++){
	            if(i-j*j>=0){
	            dp[i]=min(dp[i],dp[i-j*j]);
	            }
	        }
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,-1);
	    return solveMem(n,dp);
	}
