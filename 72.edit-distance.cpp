/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:

    //first AC 2020.03.19 Time#36.12% Memory#71.88% 
    //second AC change 2-vector to 1-vector Time#91.02% Memory#100% 
    //Dynamic Programming  use methods similar problem#10
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> res (n+1,0);
        for(int i = 0;i <=m;++i){
            int pre = res[0];
            res[0] = i;
            for(int j = 1;j <= n;++j){
                int temp = res[j];
                if(i==0) res[j] = j;
                else res[j] = min(pre+!(word1[i-1]==word2[j-1]),min(res[j],res[j-1])+1);
                pre = temp;
            }
        }
        return res[n];
    }
};
// @lc code=end

