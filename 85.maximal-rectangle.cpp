/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:

//fisrt AC 2020.03.23 Time#28.11% Memory#100% 
//using method in problem 84
    /*
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size(); if(m == 0) return 0;
        const int n = matrix[0].size();
        int max_area = 0;
        vector<int> v (n+1,0);
        for(int i = 0;i < m;++i){
            stack<int> vec;
            vector<char> vchar = matrix[i];
            vchar.push_back('0');
            for(int j = 0;j<=n;++j){
                v[j] = vchar[j]=='0'?0:v[j]+1;

            while(!vec.empty() && v[vec.top()]>v[j])
            {
                int h = v[vec.top()];
                vec.pop();
                int s = vec.empty()? -1 : vec.top();
                max_area = max(max_area, h*(j-s-1));
            }
             vec.push(j);
            }
        }
        return max_area;
    }
    */


    //!!!
    //high quality method!
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size(); if(m == 0) return 0;
        const int n = matrix[0].size();
        int max_area = 0;
        vector<int> hei (n,0), left (n,0), right (n,n);
        
        for(int i = 0;i < m;++i){
            int cur_left = 0 ,cur_right = n;
            for(int j = 0;j < n;++j)
                hei[j] = matrix[i][j]=='0'? 0:hei[j]+1;
            for(int j = 0;j < n;++j)
                if(matrix[i][j]=='1') left[j] = max(left[j],cur_left);
                else {left[j] = 0; cur_left = j+1;}
            for(int j = n-1;j >= 0;--j)
                if(matrix[i][j]=='1') right[j] = min(right[j],cur_right);
                else {right[j] = n; cur_right = j;}
            for(int j = 0;j<n;++j)
                max_area = max(max_area,(right[j]-left[j])*hei[j]);
        }
        return max_area;
    }
};
// @lc code=end

