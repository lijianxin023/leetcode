/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> outcome;
        stack<pair<int,int> > dightStack;


        if(digits.empty()) //notice the boundary!!!
            return outcome;
        dightStack.push(make_pair(digits[0]-'2',0));
        const int len = digits.length();

        string str;
        while(!dightStack.empty()){
             auto it = dightStack.top();
             dightStack.pop();
             int &i = it.first;
             int &j = it.second;

             if(j==v[i].length()){
                str.pop_back();
                 continue;
             }
                
            str+=v[i][j++];
            dightStack.push(it);

            if(str.length()==len){
                outcome.push_back(str);
                str.pop_back();
            }
            else dightStack.push(make_pair(digits[str.length()]-'2',0));
               
            
        }
        return outcome;
    }
};
// @lc code=end

