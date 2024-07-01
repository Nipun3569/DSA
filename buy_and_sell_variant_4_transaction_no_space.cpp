int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        // Initialize dp table with size (n+1) x (2k+1)
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);

        for (int index = n-1; index >= 0; index--) {
            for (int operationNo = 0; operationNo < 2*k; operationNo++) {
                int profit = 0;
                if (operationNo % 2 == 0) {
                    // Buy allowed
                    int buyKaro = -prices[index] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(buyKaro, skipKaro);
                } else {
                    // Sell allowed
                    int sellKaro = prices[index] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(sellKaro, skipKaro);
                }
                curr[operationNo] = profit;
            }
            next=curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        //n is for index so it is going from 0 to n that y taken n instead of n+1
        //col is for k so total transaction are 2*k
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return solveTab(k,prices);
    }
};
