/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
map<int,int> m;
    int numSquares(int n) {
        if(n==0) return 0;
        if(m.count(n)) return m[n];
        int k = sqrt(n);
        if(k==1)  return n;

        int res = n;
        for(int i = k;i>0;--i){
            int num = i*i;
            int temp = n/num+numSquares(n%num);
            if(temp<res) res = temp;
        }
        m[n] = res;
        return res;
    }


};
// @lc code=end

