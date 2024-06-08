#include<limits.h>
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
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	int ans=solve(n,x,y,z);
	if(ans<0){
		return 0;
	}

	return ans;
}
