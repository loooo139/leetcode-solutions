/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (61.32%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    22.8K
 * Total Submissions: 37.2K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abc"
 * 输出: 3
 * 解释: 三个回文子串: "a", "b", "c".
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aaa"
 * 输出: 6
 * 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 注意:
 * 
 * 
 * 输入的字符串长度不会超过1000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            helper(s,i,i,res);
            helper(s,i,i+1,res);
        }
        return res;
    }
    void helper(const string &s,int left,int right,int &res){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            res++,left--,right++;
        }

    }
};
// @lc code=end

