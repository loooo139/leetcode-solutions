/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (28.86%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 111.3K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 示例 1:
 *
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 *
 * 示例 2:
 *
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int longestValidParentheses(string s) {
    int res = helper(s);
    reverse(s.begin(), s.end());
    for (auto &i : s) i ^= 1;
    //   cout<<res<< ' '<<helper(s)<<endl;
    return max(res, helper(s));
  }
  int helper(string s) {
    int res = 0;
    for (int i = 0, start = 0, sum = 0; i < s.size(); i++) {
      if (s[i] == '(')
        sum += 1;
      else {
        sum--;
        if (sum < 0) {
          start = i + 1;
          sum = 0;
        } else if (sum == 0)
          res = max(res, i - start + 1);
      }
      //   cout<<start<< ' '<<i<<' '<<sum<<endl;
    }
    return res;
  }
};
// @lc code=end
