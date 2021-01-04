/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN),pre_buy(INT_MIN),sell(0),pre_sell(0);
        for(int price:prices){
            pre_buy = buy;
            buy = max(buy,pre_sell-price);
            pre_sell = sell;
            sell = max(sell,price+pre_buy);
        }
        return sell;
    }
};
// @lc code=end

