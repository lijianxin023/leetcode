/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    //backtrack!!!
    bool exist(vector<vector<char>>& board, string &word, int i, int j, int pos){
        if(pos == word.size()) return true;
        if(i < 0 || i>=board.size() || j < 0 || j>=board[0].size()) return false;
        bool tag = false;
        if(board[i][j]==word[pos]){
            char c = board[i][j];
            board[i][j] ^= 255;
            tag = exist(board, word, i-1, j, pos+1)\
            || exist(board, word, i+1, j, pos+1)\
            || exist(board, word, i, j-1, pos+1)\
            || exist(board, word, i, j+1, pos+1);
            board[i][j] ^= 255;
        }
        return tag;
    }


    bool exist(vector<vector<char>>& board, string word) {
        bool tag = false;
        for(int i = 0;i<board.size() && !tag ;++i)
            for(int j = 0;j<board[0].size() && !tag;++j)
                tag = exist(board, word, i, j, 0);
        return tag;
    }
};
// @lc code=end

