/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (29.82%)
 * Likes:    1892
 * Dislikes: 77
 * Total Accepted:    210.4K
 * Total Submissions: 680.2K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,-1);
        dp[0]=0;
        for(int i=coins.front();i<=amount;i++){
            int tmp=INT_MAX;
            for(auto j:coins){
                if(i>=j&&dp[i-j]!=-1){
                    tmp=min(tmp,dp[i-j]+1);
                }
            dp[i]=tmp==INT_MAX?-1:tmp;
            }
        }
        return dp[amount];
    }
};

