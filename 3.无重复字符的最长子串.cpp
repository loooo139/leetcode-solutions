/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.24%)
 * Likes:    2899
 * Dislikes: 0
 * Total Accepted:    302.1K
 * Total Submissions: 935.6K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int res=0;
        // int left=-1;
        // vector<int>nums(256,-1);
        // for(int i=0;i<s.size();i++){
        //     left=max(left,nums[s[i]]);
        //     res=max(res,i-left);
        //     nums[s[i]]=i;
        // }
        // return res;
        int res=0;
        int left=0;
        vector<int>nums(256,0);
        for(int i=0;i<s.size();i++){
            nums[s[i]]++;
            while(left<s.size()&&(nums[s[i]]>1))nums[s[left++]]--;
            res=max(res,i-left+1);
        }
        return res;
    }
};
// @lc code=end

