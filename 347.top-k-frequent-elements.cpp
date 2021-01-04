/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(int i : nums) ++counts[i];

        vector<vector<int>> buckets(nums.size()+1);
        for(auto &k : counts)
            buckets[k.second].push_back(k.first);
        reverse(begin(buckets),end(buckets));
        
        vector<int> res;
        for(auto & bucket : buckets)
            for(auto i : bucket){
                res.push_back(i);
                if(res.size() == k) return res;
            }
        return res;
    }
};
// @lc code=end

