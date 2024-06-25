int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){

            int ans=INT_MAX;
            int prev1=nums1[index-1];
            int prev2=nums2[index-1];
            if (swapped) {
            swap(prev1, prev2);
        }
       
        // no swap scenario
        if (nums1[index] > prev1 && nums2[index] > prev2) { // strictly increasing
            ans = dp[index+1][0];
        }

        // swap scenario
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans=min(ans,1+dp[index+1][1]);
        }
         dp[index][swapped]=ans;
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //it means that the previous indexes were swapped or not
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solveTab(nums1,nums2);
    }
};
