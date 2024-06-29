class Solution {
public:
     int solve(int index,int buy,vector<int> &prices,int limit){
        if(index==prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
       int profit=0;
        if(buy){
            profit=max((-prices[index]+solve(index+1,0,prices,limit)),(0+solve(index+1,1,prices,limit)) );

        }
        else{
            profit=max((+prices[index]+solve(index+1,1,prices,limit-1)),(0+solve(index+1,0,prices,limit)));
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices,2);
    }
};
