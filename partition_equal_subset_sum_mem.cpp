class Solution{
public:
   
      bool solveMem(int index, int arr[], int N, int target, vector<vector<int>> &dp) {
        if (target == 0) {
            return true;
        }
        if (index >= N || target < 0) {
            return false;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        bool incl = solveMem(index + 1, arr, N, target - arr[index], dp);
        bool excl = solveMem(index + 1, arr, N, target, dp);
        
        return dp[index][target] = incl or excl;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        
        if(total& 1){
            return 0;
        }
        int target=total/2;
       // return solve(0,arr,N,target);
       //first changing parameter is index which goes to N
       //second changing paramter is targetwhich is of target size
      vector<vector<int>> dp(N, vector<int>(target + 1, -1));
        return solveMem(0, arr, N, target, dp);
    }
};
