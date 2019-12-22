/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (42.18%)
 * Likes:    2003
 * Dislikes: 98
 * Total Accepted:    218.8K
 * Total Submissions: 518.1K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>vals(nums.begin(),nums.end());
        int res=0;
        for(auto i:nums){
            if(!vals.count(i))continue;
            vals.erase(i);
            int pre=i-1,next=i+1;
            while(vals.count(pre))vals.erase(pre--);
            while(vals.count(next))vals.erase(next++);
            res=max(res,next-pre-1);
        }
        return res;
    }
};

