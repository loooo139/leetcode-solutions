/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.40%)
 * Likes:    1887
 * Dislikes: 0
 * Total Accepted:    123.5K
 * Total Submissions: 339.1K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 *
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *
 * 你可以假设 nums1 和 nums2 不会同时为空。
 *
 * 示例 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * 则中位数是 2.0
 *
 *
 * 示例 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * 则中位数是 (2 + 3)/2 = 2.5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int findTopk(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2,
               int k) {
    if (idx1 >= nums1.size()) return nums2[idx2 + k - 1];
    if (idx2 >= nums2.size()) return nums1[idx1 + k - 1];
    if (k == 1) return min(nums1[idx1], nums2[idx2]);

    int nums1Median =
        (idx1 + k / 2 - 1 >= nums1.size()) ? INT_MAX : nums1[idx1 + k / 2 - 1];
    int nums2Median =
        (idx2 + k / 2 - 1 >= nums2.size()) ? INT_MAX : nums2[idx2 + k / 2 - 1];

    if (nums1Median < nums2Median)
      return findTopk(nums1, idx1 + k / 2, nums2, idx2, k - k / 2);
    else
      return findTopk(nums1, idx1, nums2, idx2 + k / 2, k - k / 2);
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    return (findTopk(nums1, 0, nums2, 0, (len1 + len2 + 1) / 2) +
            findTopk(nums1, 0, nums2, 0, (len1 + len2 + 2) / 2)) /
           2.0;
  }
};
// @lc code=end
