int solveMem(vector<int> &nums,int n,vector<int> &dp){
    
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    //step 3
    if(dp[n]!=-1){
        return dp[n];
    }

    int incl=solve(nums, n-2)+nums[n];
    int excl=solve(nums,n-1)+0;
    //step 2
    dp[n]=max(incl,excl);
    return dp[n];

}
int maximumNonAdjacentSum(vector<int> &nums){
     
     //int n=nums.size();
     //right to left
     //int ans=solve(nums,n-1);

     //return ans;

     int n=nums.size();

     vector<int> dp(n,-1);

     return solveMem(nums,n-1,dp);
}
