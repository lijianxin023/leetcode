/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

//first AC 
//2020.03.11
//runtime too slow
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;

        map<int,vector<vector<int>> > target_map;

        target_map[target] = {{}};

        for(auto it = candidates.rbegin();it!= candidates.rend();++it){
            int now = *it;
            for(auto tar:target_map){
                int t = tar.first-now;
                vector<vector<int>> t_vec = tar.second;

                while(t>=0){
                    for(vector<int> &v :t_vec)
                        v.push_back(now);
                    if(t==0)
                        for(vector<int> &v :t_vec){
                            sort(v.begin(),v.end());
                            result.push_back(v);
                        }
                    else{
                        if(target_map.count(t)==0)
                            target_map[t] = t_vec;
                        else for(vector<int> &v :t_vec)
                            target_map[t].push_back(v);
                    }
                    t -=now;
                }
            }
        }
        return result;
    }
};
// @lc code=end

