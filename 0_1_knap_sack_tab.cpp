int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity) {
    // Step 1: Create a 2D dp array with dimensions n x (capacity + 1)
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Step 2: Analyze base case
    for (int w = weight[0]; w <= capacity; w++) {
        dp[0][w] = value[0];
    }

    // Fill the dp array
    for (int index = 1; index < n; index++) {
        for (int w = 0; w <= capacity; w++) {
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            int exclude = dp[index - 1][w];

            dp[index][w] = max(exclude, include);
        }
    }

    return dp[n - 1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	

   return solveTab(weight, value,n, maxWeight);
}
