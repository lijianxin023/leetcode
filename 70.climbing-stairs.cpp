/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int f = 1,s = 2,res;
        for(int i = 0;i < n-2 ; ++i){
            res = f+s;
            f = s;
            s = res;
        }
        return res;
    }
};
// @lc code=end

