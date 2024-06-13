int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>> &dp){
   
   //base case
   //if only 1 item to steal compare its weight to knapsack capacity
   if(index==0){
	   if(weight[0]<=capacity){
		   return  value[0];
	   }
	   else{
		   return 0;
	   }
   }
   
   if(dp[index][capacity]!=-1){
      return dp[index][capacity];
   }
   int include=0;
   if(weight[index]<=capacity){
	   include=value[index]+ solveMem(weight,value,index-1,capacity-weight[index],dp);
   }
   int exclude=0+solveMem(weight,value,index-1,capacity,dp);

   dp[index][capacity]=max(exclude,include);
   return dp[index][capacity];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	//return solve(weight,value,n-1,maxWeight);

   vector<vector<int>> dp(n,vector<int>(maxWeight+1, -1));//n rows and vector<int> columns of 
   //max weight+1 and initialize to -1

   return solveMem(weight, value,n-1, maxWeight,dp);
}
