/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

//runtime two slow
class Solution {
public:


    //second AC Time#82.94% Memory#50%
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for(int i = 0;i<nums.size();++i){
            
            int tar = -nums[i];
            
            if(tar<0)
                break;

            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                int sum = nums[left]+nums[right];
                if(sum > tar)
                    --right;
                else if (sum < tar)
                    ++left;
                else {
                    vector<int> temp  = {nums[i],nums[left],nums[right]};
                    result.push_back(temp);
                    while(left < right && nums[left] == temp[1]) ++left;
                    while(right > left && nums[right] == temp[2]) --right;
                }
            }

            while(i+1 <nums.size() && nums[i] == nums[i+1])
                ++i;
        }
        return result;
    }



    //first AC too slow and complicated
    /*
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator low,up;
        low = lower_bound (nums.begin(),nums.end(),0);
        up = upper_bound (nums.begin(),nums.end(),0);

        vector<vector<int>> result;

        bool zero_tag = false;

        if(low != nums.end() && *low == 0)
            zero_tag = true;
        if(up - low >=3)
            result.push_back({0,0,0});

        int last_first = 0, last_second = 0;

        for(auto it = nums.begin();it!=low;++it){
            int v = *it;
            if(v==last_first)
                continue;

            last_first = v;
            last_second = 0;

            for(auto it_second = up;it_second!= nums.end();++it_second){

                int u = *it_second;
                if(u == last_second)
                    continue;
                
                last_second = u;
                vector<int> temp;
                temp.push_back(v);
                int z = 0-u-v;

                if(z>0 && z>=u){
                    if(binary_search(it_second+1,nums.end(),z)){
                        temp.push_back(u);
                        temp.push_back(z);
                        result.push_back(temp);
                    }
                }
                else if(z==0 && zero_tag){
                    temp.push_back(0);
                    temp.push_back(u);
                    result.push_back(temp);
                }
                        
                else if(z<0)
                    if(binary_search(it+1,low,z)){
                        temp.push_back(z);
                        temp.push_back(u);
                        result.push_back(temp);
                    }
            }
        }
        return result;
    }
    */
};
// @lc code=end

