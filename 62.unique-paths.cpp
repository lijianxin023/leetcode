/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    //first AC 2020.03.18 all 100%
    int uniquePaths(int m, int n) {
        vector<int> num (m,1);
        for(int i = 1;i<n;++i){
            vector<int> temp = num;
            for(int j = 1;j<m;++j)
                num[j] = temp[j]+num[j-1];
        }
        return num[m-1];
    }
};
// @lc code=end

