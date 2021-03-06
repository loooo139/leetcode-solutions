/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (57.55%)
 * Likes:    950
 * Dislikes: 80
 * Total Accepted:    112.8K
 * Total Submissions: 195.1K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp=0;
        for(auto i:nums)tmp^=i;
        int k=0;
        while((tmp>>k&1)!=1)k++;
        //cout<<k<<endl;
        int n1=0;
        for(auto i:nums){
            if(i>>k&1){
                n1^=i;
            }
        }
        return {n1,n1^tmp};
    }
};

