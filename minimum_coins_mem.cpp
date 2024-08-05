int solve(vector<int> &nums,int x,vector<int> &dp){
    if(x==0){
        return 0;

    }
    if(x<0){
        return INT_MAX;
    }
    
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini=INT_MAX;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int ans=solve(nums,x-nums[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    dp[x]=mini;
    return dp[x];
}
