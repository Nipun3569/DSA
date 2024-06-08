#define MOD 1000007
#include<vector>
long long int solveMem(int n, vector<long long int>& dp) {
    // Base cases
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    // Check if the result is already computed
    if (dp[n] != -1) {
        return dp[n];
    }
   
    // Compute the result using the recurrence relation
    dp[n] = ((n - 1) * (solveMem(n - 1, dp) + solveMem(n - 2, dp)) % MOD) % MOD;

    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n + 1, -1);
    return solveMem(n, dp);
}
