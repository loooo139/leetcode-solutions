/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.27%)
 * Total Accepted:    273.6K
 * Total Submissions: 643.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        if (height.size() <= 2)
            return 0;
        vector<int> nums(height.size(), 0);
        int max_height = 0;
        for (int i = 0; i < height.size(); i++)
        {
            nums[i] = max_height;
            max_height = max(max_height, height[i]);
        }
        int res = 0;
        max_height = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            nums[i] = min(nums[i], max_height);
            if (height[i] < nums[i])
                res += nums[i] - height[i];
            max_height = max(height[i], max_height);
        }
        return res;
    }
};
