#include <bits/stdc++.h>

int solve(vector<int> &num,int tar){
    //base case
    if(tar<0){
        return 0;
    }
    if(tar==0){
        return 1;
    }
    
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solve(num,tar-num[i]);
    }
    return ans;
}
int findWays(vector<int> &num, int tar)
{
    
    return solve(num,tar);
}