/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j)
                if(grid[i][j]=='1'){
                    res+=1;
                    killlands(i,j,grid);
                }     
        }
        return res;
    }

    void killlands(int i,int j,vector<vector<char>>& grid){
        if(grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        if(i>0)
            killlands(i-1,j,grid);
        if(j>0)
            killlands(i,j-1,grid);
        if(i<grid.size()-1)
            killlands(i+1,j,grid);
        if(j<grid[0].size()-1)
            killlands(i,j+1,grid);
    }
};
// @lc code=end

