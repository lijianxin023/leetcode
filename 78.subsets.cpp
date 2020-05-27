/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
//fisrt AC 2020.03.19 Time#97.35% Memory#100% 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res {{}};
        for(int i = 0;i<nums.size();++i){
            int n = res.size();
            for(int j = 0;j<n;++j){
                vector<int> v = res[j];
                v.push_back(nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};
// @lc code=end

