/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
//first AC 2020.03.19 Time#68.87% Memory#100%
    void sortColors(vector<int>& nums) {
        const int n = nums.size();
        int i = 0,l = 0,r = n;
        while(i<r){
            if(nums[i]==1) ++i; //delete || i<l
            else if(nums[i]==0) swap(nums[i++],nums[l++]); //change i to i++ then time 100%
            else swap(nums[i],nums[--r]);
        }
        return;
    }


};
// @lc code=end

