class Solution {
public:
    int solve(int index,vector<int> &slices,int n){
        //base case
        if(n==0 || index>=slices.size()){
            return 0;
        }
        int take=slices[index]+solve(index+2,slices,n-1);
        int nottake=0+solve(index+1,slices,n);
        return max(take,nottake);


    }
    int maxSizeSlices(vector<int>& slices) {
        
        int k=slices.size();
        int case1=solve(0,slices,k/3);
        int case2=solve(1,slices,k/3);
        return max(case1,case2);
    }
};
