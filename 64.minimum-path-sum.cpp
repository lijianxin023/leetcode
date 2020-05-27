/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
//first AC 2020.03.18 Time#87.56% Memory#100% use sorting
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> num = grid[0];
        const int m = grid.size(),n = num.size();
        for(int i = 1;i<n;++i)
            num[i] += num[i-1];
        for(int i = 1;i<m;++i){
            vector<int> temp = num;
            num[0] += grid[i][0];
            for(int j = 1;j<n;++j)
                num[j] = grid[i][j]+min(temp[j],num[j-1]);
        }
        return num[n-1];
    }
};
// @lc code=end

