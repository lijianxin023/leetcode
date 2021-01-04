/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res (num+1,0);
        int it = 1, d = 1;
        while(it <= num){
            for(int i = 0;i < d&&it <= num; ++i,++it){
                res[it] = res[i] + 1; 
            }
            d *= 2;
        }
        return res;
    }
};
// @lc code=end

