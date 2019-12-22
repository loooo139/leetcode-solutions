/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (39.15%)
 * Likes:    452
 * Dislikes: 142
 * Total Accepted:    132.4K
 * Total Submissions: 336K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        
        int left=0,right=n-1;
        if(nums[left]<nums[right])return nums[left];
        while(left!=right-1){
            int mid=left+(right-left)/2;
            if(nums[right]>nums[mid])
                right=mid;
            else if(nums[left]<nums[mid])
                left=mid;
            else if(nums[right]==nums[mid])
                right--;
            else
            {
                left++;
            }
            
        }
        return nums[right];
    }
};

