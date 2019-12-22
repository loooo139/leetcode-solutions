/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.60%)
 * Total Accepted:    510.8K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (!nums.empty() && nums.back() < 0)
            return {};
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0)
                break;
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1])
                        ++i;
                    while (i < j && nums[j] == nums[j - 1])
                        --j;
                    ++i;
                    --j;
                }
                else if (nums[i] + nums[j] < target)
                    ++i;
                else
                    --j;
            }
        }
        return res;
    }
};
