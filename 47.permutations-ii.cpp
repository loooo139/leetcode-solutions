/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
/**
 * @brief  
 * @note   
 * @retval None
 */
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        DFS(nums, 0, res);
        return res;
    }
    void DFS(vector<int> nums, int start, vector<vector<int>> &res)
    {
        if (start >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (i != start && (nums[i] == nums[start]))
                continue;
            swap(nums[i], nums[start]);
            DFS(nums, start + 1, res);
        }
    }
};
