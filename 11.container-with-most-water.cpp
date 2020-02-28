/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

//first AC
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxA = (right-left) * min(height[left],height[right]);
        while (left < right-1)
        {
            if(height[left]<=height[right]){
                ++left;
                if(height[left]>height[left-1]){
                        int newArea = (right-left)* min(height[left],height[right]);
                        if(newArea>maxA)
                            maxA = newArea;
                    }  
            }
            else{
                    --right;
                   if(height[right]>height[right+1]){
                        int newArea = (right-left)* min(height[left],height[right]);
                        if(newArea>maxA){
                            maxA = newArea;
                        }
                    } 
            }    
        }
        return maxA;
    }
};
// @lc code=end

//method 1 Brute force search O(n2)

//