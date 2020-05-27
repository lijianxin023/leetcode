/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:

    //fisrt AC 2020.03.26 Time#97.77% Memory#100% 
    int maxProfit(vector<int>& prices) {
        int profit = 0, bp = INT_MAX;
        for(int &x:prices){
            if(x<bp)
                bp = x;
            else profit = max(profit,x-bp);
        }
        return profit;
    }
};
// @lc code=end

