/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (59.81%)
 * Likes:    313
 * Dislikes: 0
 * Total Accepted:    64.5K
 * Total Submissions: 107.7K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums,0,nums.size()-1,nums.size()+1-k);
    }
    int quickSort(vector<int>&nums,int begin,int end,int pos){
        if(begin>=end)return nums[begin];
        int tmp=nums[begin];
        int l=begin,r=end;
        while(l<r){
            while(l<r&&nums[r]>=tmp)r--;
            nums[l]=nums[r];
            while(l<r&&nums[l]<=tmp)l++;
            nums[r]=nums[l];
        }
        nums[l]=tmp;
        int finalPos=l-begin+1;
        // if(finalPos>=pos)return quickSort(nums,begin,l,pos);
        // else return quickSort(nums,l+1,end,pos-finalPos);
        if(pos-1<=l)return quickSort(nums,begin,l,pos);
        else return quickSort(nums,l+1,end,pos);
    }
};
// @lc code=end

