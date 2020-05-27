/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start


//first AC 2020.3.16
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int result = 0;
        int now_height = 0;

        for(int i = 0;i<height.size();++i){
            int hei = height[i];
            if(hei == 0)
                continue;
            if(!s.empty()){
                int low_height = 0; //计算的起始线
                while(!s.empty()){
                    int it = s.top();
                    int it_hei = height[it];

                    int min_hei = min(hei,it_hei);
                    result += (i-it-1)*(min_hei-low_height);

                    if(hei > it_hei){
                         low_height = it_hei;
                         s.pop();
                    }                    
                    else if(hei <= it_hei)
                       break;   
                }
            }
            s.push(i); //压栈
        }
        return result;
    }
};
// @lc code=end

