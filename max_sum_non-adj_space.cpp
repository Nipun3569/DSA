int solve_space(vector<int> &nums){
    
    int n=nums.size();
    int prev2=0;
    int prev1=nums[0];
    
    for(int i=1;i<n;i++){
    int incl=prev2+nums[i];
    int excl=prev1+0;
    int ans=max(excl,incl);

    prev2=prev1;
    prev1=ans;
    }
    return prev1;
    

}
int maximumNonAdjacentSum(vector<int> &nums){
     
     //int n=nums.size();
     //right to left
     //int ans=solve(nums,n-1);

     //return ans;

     //int n=nums.size();

     //vector<int> dp(n,-1);

     return solve_space(nums);
}
