/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (54.71%)
 * Likes:    2257
 * Dislikes: 82
 * Total Accepted:    507.3K
 * Total Submissions: 923.7K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0,n=nums.size()-1;
        while(i<=n){
            if(nums[i]!=0)nums[j++]=nums[i++];
            else i++;
        }
        while(j<=n)nums[j++]=0;
    }
};

