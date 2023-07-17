class Solution {
private:
void solve(vector<int> nums,int index,vector<vector<int>>& ans){
    //base case
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,index+1,ans);

        //backtrack
//original string mei he changes kar rahe hai isliye backtrack krna padega
         swap(nums[index],nums[j]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      int index=0;
      solve(nums,index,ans);
      return ans;  
    }

};
