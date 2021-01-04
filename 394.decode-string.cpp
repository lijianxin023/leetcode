/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> TimeS;
        stack<string> StringS;
        int i = 0;
        string temp;
        while(i<s.size()){
            char c = s[i];
            if(c>='a' && c<='z')
                temp.push_back(c);
            else if(c>='0' && c<='9'){
                int num = c-'0';
                while(s[++i]!='[')
                    num = num*10 + s[i]-'0';
                if(TimeS.empty())
                    res+=temp;
                else StringS.push(temp);
                temp.clear();
                TimeS.push(num);
            }
            else if(c==']'){
                int k = TimeS.top();
                TimeS.pop();
                string newTemp;
                if(!StringS.empty()){
                    newTemp = StringS.top();
                    StringS.pop();
                }
                for(int j = 0; j < k; ++j){
                    newTemp+=temp;
                }
                temp = newTemp;
            }
            ++i;
        }
        res += temp;
        return res;
    }
};
// @lc code=end

