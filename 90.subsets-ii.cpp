/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.44%)
 * Total Accepted:    190.7K
 * Total Submissions: 458.9K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> path;
        vector<vector<int>> res;
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        subsetsWithDupDFS(nums, 0, path, res);
        return res;
    }
    void subsetsWithDupDFS(vector<int> nums, int index, vector<int> &path, vector<vector<int>> &res)
    {
        res.push_back(path);
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            subsetsWithDupDFS(nums, i + 1, path, res);
            path.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
    }
};
