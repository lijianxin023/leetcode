/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int len = nums.size();
        int val = nums.back(),i = len-2;
        while(i>=0){
            if(nums[i]>=nums[i+1])
                --i;
            else break;
        }
        if(i>=0){
            int j = i+1;
            while(j+1<len && nums[j+1] >nums[i])
                ++j;
            swap(nums[i],nums[j]);
            sort(nums.begin()+i+1,nums.end());
        }
        else sort(nums.begin(),nums.end());
    }
};
// @lc code=end

