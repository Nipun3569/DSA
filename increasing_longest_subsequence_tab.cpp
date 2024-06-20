//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int n,int a[],int curr,int prev){
        //bae case
        if(curr==n){
            return 0;
        }
        
        //include/
        //1st always included
        int take=0;
        if(prev==-1 || a[curr]>a[prev]){
            take=1+solve(n,a,curr+1,curr);//prev=curr
        }
        
        //exclude
        int notTake=0+solve(n,a,curr+1,prev);
        
        return max(take,notTake);
        
    }
    int solveMem(int n,int a[],int curr,int prev,vector<vector<int>> &dp){
        //bae case
        if(curr==n){
            return 0;
        }
        
        //include/
        //1st always included
        int take=0;
        if(prev==-1 || a[curr]>a[prev]){
            take=1+solveMem(n,a,curr+1,curr,dp);//prev=curr
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //exclude
        int notTake=0+solveMem(n,a,curr+1,prev,dp);
        dp[curr][prev+1]=max(take,notTake);//taaki invalid index n bane
        return dp[curr][prev+1];
        
    }
    
    int solveTab(int n,int a[]){
        // Initialize dp table with 0s
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the dp table from the bottom up
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = curr-1; prev >= -1; prev--) {
                // Take the current element if it is larger than the previous element in the subsequence
                int take = 0;
                if (prev == -1 || a[curr] > a[prev]) {
                    take = 1 + dp[curr+1][curr+1];
                }

                // Not take the current element
                int notTake = 0 + dp[curr+1][prev+1];

                // Store the result in the dp table
                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
        
    }
    int longestSubsequence(int n, int a[])
    {
       //currindex=0; previndex=-1
       //vector<vector<int>> dp(n,vector<int>(n+1,-1));
       //return solveMem(n,a,0,-1,dp);
       return solveTab(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
