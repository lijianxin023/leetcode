/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(),n = matrix[0].size();
        return search(matrix,target,0,0,m-1,n-1);
    }
    bool search(vector<vector<int>>& matrix, int target,\
               int l1,int l2, int h1, int h2){
        if(l1>h1||l2>h2)
            return false;
        int mid1= (l1+h1)/2;
        int mid2= (l2+h2)/2;
        int num = matrix[mid1][mid2];
        if(num==target)
            return true;
        else if(num>target)
            return search(matrix,target,l1,l2,mid1-1,h2)||\
                    search(matrix,target,mid1,l2,h1,mid2-1);
        else return search(matrix,target,mid1+1,l2,h1,h2)||\
                    search(matrix,target,l1,mid2+1,mid1,h2);
    }
};
// @lc code=end

