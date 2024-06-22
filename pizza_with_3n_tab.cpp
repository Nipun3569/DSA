int solveTab(vector<int> &slices){
        int k=slices.size();
    vector<vector<int>> dp1(k+2,vector<int> (k+2,0));
    
    for(int index=k-2;  index>=0;index--){
        for(int n=1;n<=k/3;n++){
        int take=slices[index]+dp1[index+2][n-1];//here index+2 ans we are taking max value as
        //k-2 so we are going out of bounds so initialise it with k+2
        int nottake=0+dp1[index+1][n];
        dp1[index][n]= max(take,nottake);
        }
    }
    int case1=dp1[0][k/3];

    vector<vector<int>> dp2(k+2,vector<int> (k+2,0));

    for(int index=k-1;index>=1;index--){
        for(int n=1;n<=k/3;n++){
        int take=slices[index]+dp2[index+2][n-1];
        int nottake=0+dp2[index+1][n];
        dp2[index][n]= max(take,nottake);
        }
    }
    int case2=dp2[1][k/3];
    return max(case1,case2);

    }
    int maxSizeSlices(vector<int>& slices) {
        
       return solveTab(slices);
    }
};
