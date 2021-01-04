/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        const int m = matrix.size(),n = matrix[0].size();
        vector<int> height (n,0);
        int start_p,min_n,min_p;
        for(int i = 0;i<m;++i){
            start_p = 0;
            for(int j = 0;j<n;++j){
                if(matrix[i][j]=='1'){
                    ++height[j];
                    if(height[j]<=res)
                        start_p = j+1;
                    else{
                        if(start_p == j){
                            min_n = height[j];
                            min_p = j;
                        }
                            
                        
                        if(height[j]<=min_n){
                            min_n = height[j];
                            min_p = j;
                        }

                        res = max(res,j-start_p+1);

                        if(min_n<=res){
                            min_n = height[j];
                            start_p = min_p+1;
                            for(int k = min_p+1;k<=j;++k)
                                if(height[k]<=min_n){
                                    min_n = height[k];
                                    min_p = k;
                                }
                        }
                    }
                }
                else {
                    height[j] = 0;
                    start_p = j+1;
                }
            }
        }
        return res*res;
    }
};
// @lc code=end

