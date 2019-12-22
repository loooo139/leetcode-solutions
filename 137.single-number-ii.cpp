/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (45.59%)
 * Total Accepted:    164.2K
 * Total Submissions: 359.1K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        long temp = 1;
        for (int i = 0; i < 32; i++)
        {
            int t = 0;
            for (auto j : nums)
            {
                if (j & temp)
                    t++;
            }
            temp = temp << 1;
            res = res | ((t % 3) << i);
        }
        return res;
    }
};
