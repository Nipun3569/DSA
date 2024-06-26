int solveMem(int index,int diff,int A[],unordered_map<int,int> dp[]){
        //backward check
        if(index<0){
            return 0;
        }
        
        int ans=0;
        if(dp[index].count(diff)){
            return  dp[index][diff];
        }
        for(int j=index-1;j>=0;j--){
            if(A[index]-A[j]==diff){
                ans=max(ans,1+solve(j,diff,A));
            }
        }
        dp[index][diff]=ans;
        return dp[index][diff];
    }
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2){
          return n;
        }
        int ans=0;
        unordered_map<int,int> dp[n+1];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solveMem(i,A[j]-A[i],A,dp));
                   
            }
        }
        return ans;
    }
};
