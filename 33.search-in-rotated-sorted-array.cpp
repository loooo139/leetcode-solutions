/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.71%)
 * Total Accepted:    387.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution
{
  public:
    int search_1(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < nums[right]){
                if(target>nums[mid]&&target<=nums[right])
                    left=mid+1;
                else
                {
                    right=mid-1;
                }
                
            }
            else{
                if(nums[mid]>target&&nums[left]<=target)
                    right=mid-1;
                else 
                    left=mid+1;
            }

        }
        return -1;
    }
        int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        // 找到最小值
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back()) r = mid;
            else l = mid + 1;
        }
        
        if (target <= nums.back()) r = nums.size() - 1;
        else l = 0, r -- ;
        
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        
        if (nums[l] == target) return l;
        return -1;
    }
};
