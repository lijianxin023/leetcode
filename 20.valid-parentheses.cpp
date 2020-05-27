/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        bool tag = true;

        for(char &c:s){
            if(c=='(')
                sta.push(')');
            else if(c=='{')
                sta.push('}');
            else if(c=='[')
                sta.push(']');
            else{
                if(sta.empty()){
                    tag = false;
                    break;
                }
                char pop_char = sta.top();
                if(pop_char != c){
                    tag = false;
                    break;
                }
                sta.pop();
            }
        }
        if(!sta.empty())
            tag = false;
        return tag;
    }
};
// @lc code=end

