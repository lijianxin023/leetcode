/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:

//fisrt AC 2020.03.25 Time#100% Memory#100% 
    int numTrees(int n) {
        vector<int> num (n+1,0);
        num[0] = num[1] = 1;
        for(int i = 2;i <= n;++i){
            for(int j = 0;j < i;++j){
                num[i]+=num[j]*num[i-j-1];
            }
        }
        return num[n];
    }
};
// @lc code=end

