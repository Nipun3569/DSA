#include <bits/stdc++.h> 

long long int solve_space(vector<int> &nums){
    
    long long int n=nums.size();
    long long int prev2=0;
    long long int prev1=nums[0];
    
    for(int i=1;i<n;i++){
    long long int incl=prev2+nums[i];
    long long int excl=prev1+0;
    long long int ans=max(excl,incl);

    prev2=prev1;
    prev1=ans;
    }
    return prev1;
    

}
long long int houseRobber(vector<int>& valueInHouse)
{
    
    int n=valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }

    vector<int> first,second;

    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }
    long long int sol1=solve_space(first);
    long long int sol2=solve_space(second);

    long long int ans=max(sol1,sol2);

    return ans;



    

}
