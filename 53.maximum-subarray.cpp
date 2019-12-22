/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.02%)
 * Total Accepted:    484.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution_1
{
  public:
   /**
    * @brief  最大数组和
    * @note   
    * @param  &nums: 
    * @retval 
    */
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN, curSum = 0;
        for (int num : nums) {
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }
};
class Solution
{
  public:
   /**
    * @brief  最大数组和，动态规划
    * @note   
    * @param  &nums: 
    * @retval 
    */
    int maxSubArray(vector<int> &nums)
    {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==0||dp[i-1]<0)dp[i]=nums[i];
            else
            {
                dp[i]=dp[i-1]+nums[i];
            }
            
            res=max(res,dp[i]);
            
        }
        return res;
    }
};
