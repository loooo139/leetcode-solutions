/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.38%)
 * Likes:    1434
 * Dislikes: 0
 * Total Accepted:    135.1K
 * Total Submissions: 279K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组
 * nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 示例:
 *
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 *
 *
 * 进阶:
 *
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 *
 */

// @lc code=start
class Solution {
 public:
  int maxSubArrayDp(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, INT_MIN);
    int res = INT_MIN;
    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
      dp[i + 1] = max(nums[i], nums[i] + dp[i]);
      res = max(res, dp[i + 1]);
    }
    return res;
  }
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int mx, lmx, rmx, sum;
    maxSub(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
    return mx;
  }
  /**
   * @brief
   * @note   mx (largest sum of this subarray),
lmx(largest sum starting from the left most element),
rmx(largest sum ending with the right most element),
sum(the sum of the total subarray).
   * @param  l:
   * @param  r:
   * @retval None
   */
  void maxSub(vector<int> nums, int l, int r, int& mx, int& lmx, int& rmx,
              int& sum) {
    if (l == r) {
      mx = lmx = rmx = sum = nums[l];
      return;
    }
    int mx1, mx2, lmx1, lmx2, rmx1, rmx2, sum1, sum2;
    int m = l + r >> 1;
    maxSub(nums, l, m, mx1, lmx1, rmx1, sum1);
    maxSub(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
    sum = sum1 + sum2;
    lmx = max(lmx1, sum1 + lmx2);
    rmx = max(rmx2, sum2 + rmx1);
    mx = max(max(mx1, mx2), rmx1 + lmx2);
  }
};
// @lc code=end
