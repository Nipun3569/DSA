int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int swap=0;
        int noswap=0;
        int currswap=0;
        int currNoswap=0;
        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){

            int ans=INT_MAX;
            int prev1=nums1[index-1];
            int prev2=nums2[index-1];
            if (swapped) {
            int temp=prev2;
            prev2=prev1;
            prev1=temp;
        }
       
        // no swap scenario
        if (nums1[index] > prev1 && nums2[index] > prev2) { // strictly increasing
            ans = noswap;
        }

        // swap scenario
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans=min(ans,1+swap);
        }
        if(swapped){
            currswap=ans;
        }else{
            currNoswap=ans;
        }
            }
            swap=currswap;
            noswap=currNoswap;
        }
        return min(swap,noswap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //it means that the previous indexes were swapped or not
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solveTab(nums1,nums2);
    }
};
