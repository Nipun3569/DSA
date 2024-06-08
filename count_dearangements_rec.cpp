#define MOD 1000007
long long int countDerangements(int n) {
    // Write your code here.
    if(n==1){
        return 0;

    }
    if(n==2){
        return 1;
    }
   
   //we need to do mod mentioned in question
    int ans=(((n-1)%MOD)*((countDerangements(n-1)%MOD)+(countDerangements(n-2)%MOD))%MOD);

    return ans;
}
