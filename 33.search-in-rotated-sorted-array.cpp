/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int lo = 0,hi = n-1;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(nums[hi] > nums[mid] ) hi = mid;
            else lo = mid+1;
        }
        int pivot = lo;

        lo = 0;hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int real = (mid+pivot)%n;
            if(nums[real]>target) hi = mid-1;
            else if(nums[real]<target) lo = mid+1;
            else return real;
        }
        return -1;
    }
};
// @lc code=end

