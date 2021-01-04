/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1,high = n-1;
        int res = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int fq1 = 0,fq2 = 0,fq3 = 0;
            for(int &i:nums){
                if(i<low||i>high)
                    continue;
                if(i<mid)
                    ++fq1;
                else if(i==mid)
                    ++fq2;
                else ++fq3;
            }
                
            if(fq2>=2){
                res = mid;
                break;
            }
            else if(fq1>=fq3)
                high = mid-1;
            else low = mid+1;
        }
        return res;     
    }
};
// @lc code=end

