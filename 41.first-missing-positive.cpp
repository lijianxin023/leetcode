/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int len = nums.size();
        int result = -1;
        for(int i = 0;i<len;++i){
            int x = nums[i];
            while(x>0 && x<=i && nums[x-1] != nums[i]){
                swap(nums[x-1],nums[i]);
                x = nums[i];
            }
                
        }
        for(int i = 0;i<len;++i){
            if(nums[i]!=i+1){
                result = i+1;
                break;
            }
        }
        if(result<0)
            result = len+1;
        return result;
    }
};
// @lc code=end

