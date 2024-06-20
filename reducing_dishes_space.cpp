int solveTabSO(vector<int>& satisfaction){
        int n=satisfaction.size();
        

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        next[n]=0;
        for(int index=n-1; index>=0;index--){
            for(int time=index;time>=0;time--){

                int include=satisfaction[index]*(time+1)+ next[time+1];
                int exclude=0+next[time];
                curr[time]=max(include,exclude);
            }
            next=curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sort
        sort(satisfaction.begin(),satisfaction.end());
        //int n=satisfaction.size();
        //vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        //return solveMem(satisfaction,0,0,dp);
        return solveTabSO(satisfaction);
    }
};
