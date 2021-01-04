/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<int> ch_set[26];
        for(int i = 0;i<board.size();++i)
            for(int j = 0;j<board[0].size();++j)
                ch_set[board[i][j]-'a'].insert(i*board[0].size()+j);
        
        vector<string> res;
        for(string &word:words){
            int num = word.front()-'a';
            for(auto it:ch_set[num]){
                int i = it/board[0].size(), j = it%board[0].size();
                if(find(i,j,board,word,{})){
                    res.push_back(word);
                    break;
                }
                    
            }   
        }
        return res;
    }

    bool find(int i, int j,vector<vector<char>>& board, string word,set<int> is_found){
        if(word.empty())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return false;
        char c = word.front();
        int num = i*board[0].size()+j;
        if(board[i][j]==c && !is_found.count(num)){
            is_found.insert(num);
            return find(i-1,j,board,word.substr(1),is_found)||\
                    find(i+1,j,board,word.substr(1),is_found)||\
                    find(i,j-1,board,word.substr(1),is_found)||\
                    find(i,j+1,board,word.substr(1),is_found);
        }
        else return false;
    }
};
// @lc code=end

