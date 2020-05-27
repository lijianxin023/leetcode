/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:

    //Divide and Conquer 2020.03.17 Time#71.38% Memory#100%

    
    int maxSubArray(vector<int>& nums) {
          return maxSubArray(nums,0,nums.size()-1);
    }

private: 

    int maxSubArray(vector<int>& nums, int left ,int right) {
        if(left >right)
            return INT_MIN;
        
        int mid = (left+right)/2;
        int ml = 0,mr = 0;
        int maxleft = maxSubArray(nums,left,mid-1);
        int maxright = maxSubArray(nums,mid+1,right);
        for(int i = mid-1,sum = 0;i>=left;--i){
            sum += nums[i];
            ml = max(sum,ml);
        }
        for(int i = mid+1,sum = 0;i<=right;++i){
            sum += nums[i];
            mr = max(sum,mr);
        }
        return max(max(maxleft,maxright),ml+mr+nums[mid]);
    }

public:
    //first AC 2020.03.17 Time#98.62% Memory#100%
    /*
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int max_val = INT_MIN,temp_val = 0;
        for(int i = 0;i < n;++i){
            temp_val+=nums[i];
            max_val = (temp_val>max_val) ? temp_val : max_val;
            if(temp_val < 0)
                temp_val = 0;           
        }
        return max_val;
    }
    */
};
// @lc code=end

