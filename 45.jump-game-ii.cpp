/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start


class Solution {
public:



    //first pass but time exceed;
    /*
    int jump_from_last(int pos,vector<int>& nums){
        int times = 0;
        for(int i = 0;i<pos;++i){
            if(nums[i] + i >=pos){
                ++times;
                if(i > 0)
                    times += jump_from_last(i,nums);
                break;
            }
        }
        return times;
    }
    */

   //first AC but memmory usage too high;
   /*
    int jump_from_begin(int pos,vector<int>& nums){
        int target = nums.size()-1;
        int times = 0;

        if(pos == target)
            times = 0;
        else if(pos+nums[pos] >= target)
            times = 1; 
        else{
            int next_pos = 0;
            int max_jump = 0;
            for(int i = pos+1;i<=nums[pos]+pos;++i){
                int jump_pos = i+nums[i];
                if(jump_pos>max_jump){
                    max_jump = jump_pos;
                    next_pos = i;
                }
            }
            times = 1+jump_from_begin(next_pos,nums);
        }
        return times;
    }
    */


   //second AC  DO NOT USE BACKTRACK!;
    int jump(vector<int>& nums) {
        const int n = nums.size()-1;
        int times = 0;
        int i =0;
        while (i<n)
        {
            ++times;
            int &jump_length = nums[i];
            if(i+jump_length >=n)
                break;  
            int next_pos = 0;
            int max_jump = 0;      
            for(int j = 1;j<=jump_length;++j){
                int jump_pos = j+i;
                int next_jump_length = nums[jump_pos]+jump_pos;
                if(next_jump_length>max_jump){
                    max_jump = next_jump_length;
                    next_pos = jump_pos;
                }
            }
            i = next_pos;
        }
        return times;
    }
};
// @lc code=end

