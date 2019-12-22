/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.55%)
 * Total Accepted:    386.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),left=(m+n+1)/2,right=(m+n+2)/2;
        return (findKth(nums1,0,nums2,0,left)+findKth(nums1,0,nums2,0,right))/2.0;
    }
    int findKth(const vector<int>&nums1,int i, const vector<int>&nums2,int j,int k){
        if(i>=nums1.size())return nums2[j+k-1];
        if(j>=nums2.size())return nums1[i+k-1];
        if(k==1)return min(nums1[i],nums2[j]);
        int midVal1=(i+k/2-1<nums1.size())?nums1[i+k/2-1]:INT_MAX;
        int midval2=(j+k/2-1<nums2.size())?nums2[j+k/2-1]:INT_MAX;
        if(midVal1>midval2)return findKth(nums1,i,nums2,j+k/2,k-k/2);
        else  return findKth(nums1,i+k/2,nums2,j,k-k/2);
    }
};

