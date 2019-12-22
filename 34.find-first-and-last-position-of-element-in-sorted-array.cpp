/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.30%)
 * Likes:    1656
 * Dislikes: 89
 * Total Accepted:    313K
 * Total Submissions: 927.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        
        if (nums[r] != target) return {-1, -1};
        int start = r;
        
        l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        
        int end = r;
        return {start, end};
    }
};

