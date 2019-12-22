/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (31.64%)
 * Likes:    2038
 * Dislikes: 203
 * Total Accepted:    275.9K
 * Total Submissions: 858.8K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
 /**
  * @brief  
  * @note   dp
  * @param  nums: 
  * @retval 
  */
    bool canJump_dp(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return true;
    }
    bool canJump(vector<int>& nums){
        int reach=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i>reach||reach>=n-1)break;
            reach=max(reach,nums[i]+i);
            
        }
        return reach>=n-1;
    }
};

