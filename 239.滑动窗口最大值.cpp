/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (43.13%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    23.2K
 * Total Submissions: 53.8K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组
 * nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回滑动窗口中的最大值。
 *
 *
 *
 * 示例:
 *
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7]
 * 解释:
 *
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 *
 * 提示：
 *
 * 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 *
 *
 *
 * 进阶：
 *
 * 你能在线性时间复杂度内解决此题吗？
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    for (int i = 0; i < k - 1; i++) {
      while (!que.empty() && nums[que.front()] <= nums[i]) que.pop_front();
      que.push_front(i);
    }
    vector<int> res;
    for (int i = k - 1; i < nums.size(); i++) {
      while (!que.empty() && nums[que.front()] <= nums[i]) que.pop_front();
      que.push_front(i);
      if (k <= i - que.back()) {
        que.pop_back();
      }
      res.push_back(nums[que.back()]);
    }
    return res;
  }
};
// @lc code=end
