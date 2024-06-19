int solveTabSO(vector<int>& obstacles) {
       int n=obstacles.size()-1;
      
       vector<vector<int>> dp(4, vector<int> (obstacles.size(),1e9));
       vector<int> curr(4,INT_MAX);
       vector<int> next(4,INT_MAX);
       next[0]=0;
       next[1]=0;
       next[2]=0;
       next[3]=0;

       for(int pos=n-1;pos>=0;pos--){
        for(int currlane=1;currlane<=3;currlane++){
           if( obstacles[pos+1]!=currlane){
        curr[currlane]= next[currlane];
    }
    else{
        //sideways jump
        //since only 3 ways
        int ans=1e9;
        for(int i=1;i<=3;i++){
            if(currlane!=i &&  obstacles[pos]!=i){
            ans=min(ans,1+next[i]);//take care of pos+1
        }
        
        }
        curr[currlane]=ans;
    } 
        }
        next=curr;
       }

       return min(next[2],min(1+next[1], 1+next[3]));
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4,vector<int> (obstacles.size(),-1));
        //return solveMem( obstacles, 2,0,dp);
        return solveTabSO(obstacles);
    }
};
