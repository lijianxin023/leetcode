/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int N = nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);


        vector<vector<int>> rangeValues(nums.size(),vector<int>(nums.size(),0));

        for(int len = 1;len<=N;++len){
            for(int start = 1;start <= N-len+1;++start){
                int end = start + len -1;
                int bestcoins = 0;
                for(int final = start;final <= end; ++final){
                    int coins = nums[start-1]*nums[final]*nums[end+1];
                    coins += rangeValues[start][final-1]+rangeValues[final+1][end];
                    if(coins>bestcoins)
                        bestcoins = coins;
                }
                rangeValues[start][end] = bestcoins;
            }
        }
        return rangeValues[1][N];
    }
};
// @lc code=end

