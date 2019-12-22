/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.47%)
 * Total Accepted:    349.4K
 * Total Submissions: 672K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res(1);
        //sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int len = res.size();
            for (int j = 0; j < len; j++)
            {
                auto temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
