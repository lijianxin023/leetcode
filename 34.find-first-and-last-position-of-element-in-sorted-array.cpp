/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it_low = lower_bound(nums.begin(),nums.end(),target);
        auto it_high = upper_bound(nums.begin(),nums.end(),target);
        if(it_low == nums.end() || *it_low != target)
            return {-1,-1};
        vector<int> result;
        result.push_back(it_low-nums.begin());
        result.push_back(it_high-nums.begin()-1);
        return result;
    }
};
// @lc code=end

