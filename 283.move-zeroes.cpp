/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0,j = 0;i<nums.size();++i){
            if(nums[i]==0) ++count;
            else if(count>0){
                nums[j++] = nums[i];
                nums[i] = 0;
            }
            else ++j;  
        }

    }
};
// @lc code=end

