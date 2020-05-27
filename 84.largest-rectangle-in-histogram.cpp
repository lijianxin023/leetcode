/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:

////fisrt AC 2020.03.19 Time#5.1% Memory#100% too slow。。。

    /*
    int largestRectangleArea(vector<int>& heights) {
        vector<int> vec;
        int max_area = 0;
        for(int i = 0;i<heights.size();++i){
            if(heights[i] == 0) vec.clear();
            else {
                if(vec.empty() || heights[vec.back()] < heights[i])
                    vec.push_back(i);
                for(int j = 0;j<vec.size();++j){
                    int x = vec[j];
                    if(heights[x] >= heights[i]){
                        heights[x] = heights[i];
                        vec.resize(j+1);
                    }
                    max_area = max(max_area,(i-x+1)*heights[x]);
                }
            }
        }
        return max_area;
    }
    */

    int largestRectangleArea(vector<int>& heights) {
        stack<int> vec;
        int max_area = 0;
        heights.push_back(0);
        for(int i = 0;i<heights.size();++i){
            
            while(!vec.empty() && heights[vec.top()]>heights[i])
            {
                int h = heights[vec.top()];
                vec.pop();
                int s = vec.empty()? -1 : vec.top();
                max_area = max(max_area, h*(i-s-1));
            }
            vec.push(i);
        }
        return max_area;
    }

};
// @lc code=end

