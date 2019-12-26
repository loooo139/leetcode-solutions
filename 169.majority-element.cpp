/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.78%)
 * Total Accepted:    358.5K
 * Total Submissions: 691.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int res, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || count == 0)
            {
                res = nums[i];
                count = 1;
            }
            else if (res == nums[i])
            {
                count += 1;
            }
            else
                count -= 1;
        }
        return res;
    }
};