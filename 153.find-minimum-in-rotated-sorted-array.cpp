/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (42.74%)
 * Likes:    1010
 * Dislikes: 162
 * Total Accepted:    289.9K
 * Total Submissions: 673.2K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        //if(nums.size()==1)return nums[0];
        int n=nums.size();
        int left=0,right=n-1;
        //if(nums[left]<nums[right])return nums[left];
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<=nums.back())
                right=mid;
            else
            {
                left=mid+1;
            }
            
        }
        return nums[left];
    }
};

