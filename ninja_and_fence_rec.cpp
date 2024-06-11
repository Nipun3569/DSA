#include <bits/stdc++.h>
#define MOD 1000000007
// since we have to do modulo
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b){
    return ( (a%MOD) * (b%MOD) )%MOD;
}

int solve(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));

    }


    int ans=add(mul(solve(n-2,k),k-1), mul(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    
   return solve(n,k);
}
