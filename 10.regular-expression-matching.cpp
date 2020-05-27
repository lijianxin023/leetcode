/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start


class Solution {
public:
    // worth review
    bool isMatch(string s, string p) {
        const int s_len = s.size(),p_len = p.size();
        vector<bool> res (p_len+1,false);
        for(int i = 0;i <= s_len;++i){
            bool pre = res[0];
            res[0] = !i;
            for(int j = 1;j <= p_len;++j){
                bool temp = res[j];
                if(p[j-1]=='*')
                    res[j] = res[j-2] || (i && res[j] && (p[j-2] == s[i-1] || p[j-2]== '.'));
                else res[j] = i && pre && (p[j-1] == s[i-1] || p[j-1]=='.'); 
                pre = temp;
            }
        }
        return res[p_len];
    }



//first AC too slow
/*
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
    */
};
// @lc code=end

