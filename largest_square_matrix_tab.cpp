    int solveTab(vector<vector<int>> &mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> dp(row+1,vector<int> (col+1,0));
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
        int right=dp[i][j+1];
        int diagonal=dp[i+1][j+1];
        int down=dp[i+1][j];
        
        if(mat[i][j]==1){
             
            dp[i][j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
            
        }else{
            dp[i][j]=0;
        }
                
            }
        }
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        //i , j
        int maxi=0;
        //2 d dp since i and j changing
        vector<vector<int>> dp(n,vector<int> (m,-1));
        solveTab(mat,maxi);
        return maxi;
    }
};
