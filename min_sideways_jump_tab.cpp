int solveTab(vector<int>& obstacles) {
       int n=obstacles.size()-1;

       vector<vector<int>> dp(4, vector<int> (obstacles.size(),1e9));

       dp[0][n]=0;
       dp[1][n]=0;
       dp[2][n]=0;
       dp[3][n]=0;

       for(int pos=n-1;pos>=0;pos--){
        for(int currlane=1;currlane<=3;currlane++){
           if( obstacles[pos+1]!=currlane){
        dp[currlane][pos]= dp[currlane][pos+1];
    }
    else{
        //sideways jump
        //since only 3 ways
        int ans=1e9;
        for(int i=1;i<=3;i++){
            if(currlane!=i &&  obstacles[pos]!=i){
            ans=min(ans,1+dp[i][pos+1]);//take care of pos+1
        }
        
        }
        dp[currlane][pos]=ans;
    } 
        }
       }

       return min(dp[2][0],min(1+dp[1][0], 1+dp[3][0]));
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4,vector<int> (obstacles.size(),-1));
        //return solveMem( obstacles, 2,0,dp);
        return solveTab(obstacles);
    }
};
