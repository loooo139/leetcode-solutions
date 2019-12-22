/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (41.74%)
 * Total Accepted:    305.7K
 * Total Submissions: 724.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res, temp = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int dif = abs(sum - target);
                if (dif < temp)
                {
                    temp = dif;
                    res = sum;
                }
                if ((sum - target) > 0)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};
