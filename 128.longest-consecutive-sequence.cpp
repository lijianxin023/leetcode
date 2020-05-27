/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
//!!! do it again someday!
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int res = 0;
        for(int i:nums){
            if(m[i]) continue;
            res = max(res,m[i] = m[i+m[i+1]] = m[i-m[i-1]] = m[i+1] + m[i-1] + 1);
        }
        return res;
    }
};
// @lc code=end

