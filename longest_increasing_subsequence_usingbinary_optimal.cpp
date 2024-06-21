int optimal(int n,int a[]){
        if(n==0){
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just bada element
                //gives address of just bda element
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
       //currindex=0; previndex=-1
       //vector<vector<int>> dp(n,vector<int>(n+1,-1));
       //return solveMem(n,a,0,-1,dp);
       return optimal(n,a);
    }
};
