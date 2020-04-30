/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (43.82%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 7.5K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
 * 
 * 示例:
 * 
 * 
 * 输入: [4, 6, 7, 7]
 * 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 说明:
 * 
 * 
 * 给定数组的长度不会超过15。
 * 数组中的整数范围是 [-100,100]。
 * 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size()==0)return res;
        // sort(nums.begin(),nums.end());
        vector<int>tmp;
        dfs(nums,tmp,res,0);
        return res;
    }
	void dfs(const vector<int>nums, vector<int>path, vector<vector<int>>&res, int index) {
		//if (index >= nums.size())return;
		if (path.size() >= 2) {
			res.push_back(path);
			// helper(path);
		}
        unordered_set<int>vis;
		for (int i = index; i<nums.size(); i++) {
            if((path.empty()||nums[i]>=*path.rbegin())&&vis.find(nums[i])==vis.end()){
                path.push_back(nums[i]);
                dfs(nums,path,res,i+1);
                path.pop_back();
                vis.insert(nums[i]);
            }
		}
	}
};
// @lc code=end

