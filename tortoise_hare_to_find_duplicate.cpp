class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Phase 1: Finding the intersection point
    int tortoise = nums[0];
    int hare = nums[0];
    
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    
    // Phase 2: Finding the entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    
    return hare;
    }
};
