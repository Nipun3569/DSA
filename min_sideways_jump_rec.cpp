class Solution {
public:
int solve(vector<int>& obstacles,int currlane, int pos){
    //base case
    int n= obstacles.size();
    if(pos==n){
        return 0; 
    }

    if( obstacles[pos+1]!=currlane){
        return solve( obstacles,currlane,pos+1);
    }
    else{
        //sideways jump
        //since only 3 ways
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i &&  obstacles[pos]!=i){
        ans=min(ans,1+solve( obstacles,i,pos));//1 jump done
        }
        
        }
        return ans;
    }
}
    int minSideJumps(vector<int>& obstacles) {
        return solve( obstacles, 2,0);
    }
};
