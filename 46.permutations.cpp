/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> out;
        if (nums.size() == 0)
            return res;
        vector<bool> flag(nums.size(), false);
        DFS(nums,  res, out, flag);
        return res;
    }
    void DFS(vector<int> nums, vector<vector<int>> &res, vector<int> &out, vector<bool> &flag)
    {
        if (out.size() == nums.size())
            res.push_back(out);
        for (auto i = 0; i < nums.size(); i++)
        {
            if (!flag[i])
            {
                flag[i] = true;
                out.push_back(nums[i]);
                DFS(nums, res, out, flag);
                flag[i] = false;
                out.pop_back();
            }
        }
    }
};
