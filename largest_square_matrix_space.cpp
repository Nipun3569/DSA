int solveTabSO(vector<vector<int>> &mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> dp(row+1,vector<int> (col+1,0));
        vector<int> curr(col+1,0);//current row
        vector<int> next(col+1,0);//next row
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
        int right=curr[j+1];
        int diagonal=next[j+1];
        int down=next[j];
        
        if(mat[i][j]==1){
             
            curr[j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,curr[j]);
            
        }else{
            curr[j]=0;
        }
                
            }
            next=curr;
            
        }
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        //i , j
      
        //2 d dp since i and j changing
        int maxi=0;
        solveTabSO(mat,maxi);
        return maxi;
    }
};
