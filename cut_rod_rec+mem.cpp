#include<limits.h>
#include<vector>
int solve(int n,int x,int y,int z){
	//base case
	if(n==0){
		return 0;
	}
    
	if(n<0){
		return INT_MIN;
	}
	//including +1 for x y and z 
	int a=solve(n-x,x,y,z)+1;
	int b=solve(n-y,x,y,z)+1;
	int c=solve(n-z,x,y,z)+1;

	int ans=max(a,max(b,c));
	return ans;

}
int solveMem(int n, int x, int y, int z, vector<int> &dp) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    
    if (n < 0) {
        return INT_MIN;
    }

    // Check if the subproblem has already been solved
    if (dp[n] != -1) {
        return dp[n];
    }

    // Solve subproblems and include +1 for each valid segment cut
    int a = solveMem(n - x, x, y, z, dp) + 1;
    int b = solveMem(n - y, x, y, z, dp) + 1;
    int c = solveMem(n - z, x, y, z, dp) + 1;

    // Store the result of the subproblem
    dp[n] = max(a, max(b, c));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	//int ans=solve(n,x,y,z);
	//if(ans<0){
	//	return 0;
	//}

	//return ans;


	vector<int> dp(n+1,-1);
	int ans=solveMem(n,x,y,z,dp);
    if(ans<0){
		return 0;
	}
return ans;
}
