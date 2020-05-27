/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:

//fisrt AC 2020.03.19 Time#35.81% Memory#98% use map
// change unordered_map Time#54.03% Memory#82%
// change vector and simplicfy the code 
// substring template !!!
    string minWindow(string s, string t) {
        int begin = 0,res_head = -1,res_len = INT_MAX, tar_num = t.length();
        vector<int> m (128,0);
        for(char &c:t)  ++m[c];
        for(int i = 0;i<s.length();++i){
            if(m[s[i]]-->0) --tar_num;
            while(tar_num == 0){
                if(i-begin+1<res_len) res_len = i-(res_head = begin)+1;
                if(m[s[begin++]]++==0) ++tar_num;
            }
        }
        if(res_head == -1)
            return "";
        else return s.substr(res_head,res_len);
    }
};
// @lc code=end

