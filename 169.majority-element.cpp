/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0],times = 1,temp;
        for(int i = 1;i < nums.size();++i){
            temp = nums[i];
            if(times == 0){
                    num = temp;
                    times = 1;
                } 
            else if(temp==num) ++times;
            else --times;        
        }
        return num;
    }
};
// @lc code=end

