class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
         int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int len = 0;
            int bread = 0;
            
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) {
                    len++;
                } else {
                    ans = max(ans, len * (bread + 1));
                    len = 0;
                    bread = j + 1;
                }
            }
            
            ans = max(ans, len * (bread + 1));
        }
        
        return ans;
    
    }
};
