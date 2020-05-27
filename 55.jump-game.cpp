/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:


//first AC 2020.03.18 Time#71.69% Memory#100%
//second AC add "next" Time#97.06%
    bool canJump(vector<int>& nums) {

        int i = 0, next = 1;
        bool tag = false;
        while(i < nums.size()){
            int max_pos = i;
            if(nums[i]+i>= nums.size()-1){
                tag = true;
                break;
            }
            for(int j = max(i+1,next) ; j <= nums[i]+i ;++j)
                if(nums[j]+j > nums[max_pos]+max_pos)
                    max_pos = j;
            if(max_pos == i)
                break;
            next = nums[i]+i+1;
            i = max_pos;
        }
        return tag;
    }
};
// @lc code=end

