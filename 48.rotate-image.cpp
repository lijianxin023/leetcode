/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start


//first AC 2020.3.16 Time#81.29% Memory#100%
//Find the connection between corresponding nodes
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i < n/2;++i){
            int m = n-2*i;
            for(int j = 0;j < m-1;++j){
                int a1 = i,a2 = j+i;
                int b1 = i+j,b2 = n-1-i;
                int c1 = n-1-i,c2 = n-1-i-j;
                int d1 = n-1-i-j,d2 = i;
                swap(matrix[a1][a2],matrix[b1][b2]);
                swap(matrix[c1][c2],matrix[d1][d2]);
                swap(matrix[a1][a2],matrix[c1][c2]);
            }
        }
    }
};
// @lc code=end

