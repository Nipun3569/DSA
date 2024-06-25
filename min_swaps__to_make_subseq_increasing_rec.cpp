class Solution {
public:
   int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped) {
        // base case
        if (index == nums1.size()) {
            return 0;
        }

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // adjust the previous values if the last elements were swapped
        if (swapped) {
            swap(prev1, prev2);
        }

        // no swap scenario
        if (nums1[index] > prev1 && nums2[index] > prev2) { // strictly increasing
            ans = solve(nums1, nums2, index + 1, false);
        }

        // swap scenario
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, true));
        }

        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //it means that the previous indexes were swapped or not
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;
        
        return solve(nums1,nums2,1,swapped);
    }
};
