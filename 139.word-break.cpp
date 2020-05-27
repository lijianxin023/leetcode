/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
//fisrt AC 2020.03.30 Time#94.01% Memory#100% 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = wordDict.size(), m = s.length();
        vector<size_t> pos (n,-1);
        vector<bool> res (m+1,false);
        res[0] = true;
        for(int i = 0;i < m;++i){
          if(res[i])
            for(string &x:wordDict){
                if( x.size()+i <= m && s.substr (i,x.size()) == x)
                    res[i+x.size()] = true;
            }
        }
        if(res[m])
            return true;
        return false;
    }
};
// @lc code=end

