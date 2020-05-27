/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:

//first AC 2020.04.08 #Time 86.32% #Memory 100%
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN, last_zero = 0, tempP = 1;
        for(int x:nums){
            tempP *= x;
            maxP = max(tempP,maxP);
            if(x == 0){
                tempP = 1;
                last_zero = 0;
            }
            else if(x < 0 && last_zero == 0)
                last_zero = tempP;
            else if(last_zero < 0)
                maxP = max(maxP,tempP/last_zero);
        }
        return maxP;
    }
};
// @lc code=end

