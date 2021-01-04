/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        vector<int> pre_num (numCourses,0);
        int total_num = 0;
        for(vector<int>& v:prerequisites){
            int a = v[1],b = v[0];
            if(m.count(a) == 0)
                m[a]= {b};
            else m[a].push_back(b);
            if(pre_num[b]++==0)
                ++total_num;
        }
        stack<int> s;
        for(auto it = m.begin();it!=m.end();++it){
            int n = it->first;
            if(pre_num[n]==0)
                s.push(n);
        }

        while(!s.empty()){
            int n = s.top();
            s.pop();
            for(int i:m[n])
                if(--pre_num[i]==0){
                    s.push(i);
                    --total_num;
                }  
        }

        return (total_num==0);
    }
};
// @lc code=end

