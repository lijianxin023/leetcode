/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start

//FIRST AC using backtrack
class Solution {
public:

    void addPare(int k1,int k2,const int n,string s,vector<string> &result){
        if(k1==n && k2==0)
            result.push_back(s);
        if(k1<n)
            addPare(k1+1,k2+1,n,s+'(',result);
        if(k2>0)
            addPare(k1,k2-1,n,s+')',result);

    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> result;
        addPare(0,0,n,s,result);
        return result;
    }
};
// @lc code=end

