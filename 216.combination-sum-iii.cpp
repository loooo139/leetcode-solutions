/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (50.46%)
 * Total Accepted:    113.4K
 * Total Submissions: 224.7K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        combinationSumDFS(res, tmp, k, 1, n);
        return res;
    }

    void combinationSumDFS(vector<vector<int>> &res, vector<int> &tmp, int k, int num, int n)
    {
        if (n < 0)
            return;
        if (n == 0 && tmp.size() == k)
            res.push_back(tmp);
        for (int i = num; i < 10; i++)
        {
            tmp.push_back(i);
            combinationSumDFS(res, tmp, k, i + 1, n - i);
            tmp.pop_back();
        }
    }
};
