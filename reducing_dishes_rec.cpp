class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int time){
        //base case
        if(index==satisfaction.size()){
            return 0;
        }

        int include=satisfaction[index]*(time+1)+ solve(satisfaction,index+1,time+1);
        int exclude=0+solve(satisfaction,index+1,time);
        int ans=max(include,exclude);
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sort
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0);
    }
};
