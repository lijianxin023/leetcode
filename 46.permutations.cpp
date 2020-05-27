/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start


// similar to problem #17
// first AC 2020.3.16  Time#98.25% Memory#100%
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        const int n = nums.size();
        result.push_back(nums);
        for(int i = 1;i < n;++i){
            int now_size = result.size();
            for(int j = 0;j<now_size;++j){
                for(int k = i;k < n;++k){
                    vector<int> v = result[j];
                    swap(v[k],v[i-1]);
                    result.push_back(v);
                }
            }
        }
        return result;
    }
};
// @lc code=end

