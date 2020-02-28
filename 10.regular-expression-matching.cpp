/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

// first AC
class Solution {
public:
    bool isMatch(string s, string p) {

        
        int s_pos = 0,p_pos = 0;
        bool tag = false;

        while(p_pos < p.size()){

            //case one
            if(p_pos == 0 && p[p_pos] == '*')
                break;
            
            char c = p[p_pos++];
            bool tag_star = false; 

            while( p_pos<p.size() && p[p_pos]=='*'){
                ++p_pos;
                tag_star = true;
            }
               
            //case two
            if( c=='.' && tag_star){
                while (s_pos<=s.size())
                    if( tag = isMatch(s.substr(s_pos++),p.substr(p_pos)) )
                        break;
                break;
            }
            // case three
            else if(c=='.'){
                if(s_pos >= s.size()){
                    --p_pos;
                    break;
                }
                ++s_pos;
            }
            //case four
            else if(tag_star){
                
                if( tag = isMatch(s.substr(s_pos),p.substr(p_pos)))
                        break;
                while (s_pos<s.size() && s[s_pos] == c){
                    if( tag = isMatch(s.substr(++s_pos),p.substr(p_pos)))
                        break;
                }
                break;    
            }
            //case five
            else{
                if(s_pos >= s.size() || c != s[s_pos]){
                    --p_pos;
                    break;
                }
                ++s_pos;
            }
        }
        if(s_pos == s.size() && p_pos == p.size())
            tag = true;
        return tag;
    }
};
// @lc code=end

