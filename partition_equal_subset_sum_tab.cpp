bool solveTab(int arr[], int N,int total) {
        vector<vector<int>> dp(N+1,vector<int> (total+1,0));
        
        
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;  // Base case: a subset with sum 0 is always possible
        }
        
        for (int index = N - 1; index >= 0; index--) {
            for (int target = 0; target <= total / 2; target++) {
                bool incl = 0;
                if (target - arr[index] >= 0) {
                    incl = dp[index + 1][target - arr[index]];
                }
                bool excl = dp[index + 1][target];
                
                dp[index][target] = incl || excl;
            }
        }
        
        return dp[0][total / 2];//returning which is passed in recursion
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        
        if(total& 1){
            return 0;
        }
        int target=total/2;
       // return solve(0,arr,N,target);
       //first changing parameter is index which goes to N
       //second changing paramter is targetwhich is of target size
      return solveTab(arr,N,total);
    }
};
