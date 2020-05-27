/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int L = 0,templen = 0,numfront = 0,tempfront = 0;
        stack<pair<int,int> >  sta;

        for(int i = 0;i<s.length();++i){
            char c = s[i];
            if(c=='('){
                ++numfront;
                if(templen){
                    sta.push(make_pair(templen,tempfront));
                    tempfront = 1;
                    templen = 0;
                }
                else ++tempfront;
            }
            else if(numfront == 0)
                templen = 0;
            else{
                
                --numfront;
                --tempfront;

                while(tempfront == 0 && !sta.empty()){
                auto it = sta.top();
                sta.pop();
                tempfront = it.second;
                templen +=it.first;
                }

                
                ++templen;

                if(templen > L)
                L = templen;

            }
            
        }
        return 2*L;
    }
};
// @lc code=end

