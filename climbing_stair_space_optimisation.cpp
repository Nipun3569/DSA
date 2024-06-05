int solve4(vector<int> &cost,int n){
        
        int prev2=cost[0];
        int prev1=cost[1];

        //3rd step
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return  min(prev1,prev2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        

        //int n=cost.size();
        //int ans=min(solve(cost,n-1),solve(cost,n-2));

        //return ans;


       // int n=cost.size();
       //step 1
        //vector<int> dp(n+1,-1);
        //int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        //return ans;

        int n=cost.size();

        return solve4(cost,n);
    }
};
