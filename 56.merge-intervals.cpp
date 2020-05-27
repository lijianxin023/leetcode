/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:

    //first AC 2020.03.18 Time#71.39% Memory#100% use sorting

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];});
        int i = 0;
        vector<vector<int>> res;
        while( i < intervals.size()){
            vector<int> m = intervals[i++];
            while(i < intervals.size() && m[1] >= intervals[i][0]){
                m[1] = max(intervals[i][1],m[1]);
                ++i;
            }
            res.push_back(m);
        }
        return res;
    }
};
// @lc code=end

