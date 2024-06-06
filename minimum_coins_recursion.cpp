#include <bits/stdc++.h> 

int sloveRec(vector<int> &num,int x){
    //case case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    int mini=INT_MAX;

    for(int i=0;i<num.size();i++){
        int ans=sloveRec(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    return mini;


}
int minimumElements(vector<int> &num, int x)
{
    int ans=sloveRec(num,x);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;

}
