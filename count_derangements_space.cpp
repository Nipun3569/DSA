long long int solveTab(int n) {
    
    

    long long int prev2=0;
    long long int prev1=1;

    for(int i=3;i<=n;i++){
    
    long long int first=prev1 %MOD;
    long long int second=prev2%MOD;

    long long int sum=(first+second)%MOD;

    long long int ans=((i-1)* sum)%MOD;
    prev2=prev1;
    prev1=ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
    //vector<long long int> dp(n + 1, -1);
    //return solveMem(n, dp);

    return solveTab(n);
}