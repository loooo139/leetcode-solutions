/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (28.42%)
 * Likes:    1358
 * Dislikes: 79
 * Total Accepted:    185.3K
 * Total Submissions: 648.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = 0;
        int last = 0;
        for (int i = 1; i < n; i++) { // 依次求f[i]的值。
            while (i > last + nums[last]) // 根据i来更新last。
                last++;
            f[i] = f[last] + 1; // 根据f[last]更新f[i]。
        }
        return f[n - 1];


    }
};

