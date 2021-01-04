/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) { 
        int res1 = 0,res2 = 0;
        for(int i = 0;i<nums.size();++i){
            if (i%2==0)
                res1 =max(nums[i]+res1,res2);
            else res2 =max(nums[i]+res2,res1);
            
        }
        return max(res1,res2);
    }
};
// @lc code=end

