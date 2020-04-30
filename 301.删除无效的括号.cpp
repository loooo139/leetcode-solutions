/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 *
 * https://leetcode-cn.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (44.34%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 10.4K
 * Testcase Example:  '"()())()"'
 *
 * 删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。
 *
 * 说明: 输入可能包含了除 ( 和 ) 以外的字符。
 *
 * 示例 1:
 *
 * 输入: "()())()"
 * 输出: ["()()()", "(())()"]
 *
 *
 * 示例 2:
 *
 * 输入: "(a)())()"
 * 输出: ["(a)()()", "(a())()"]
 *
 *
 * 示例 3:
 *
 * 输入: ")("
 * 输出: [""]
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        sum++;
      else if (s[i] == ')')
        sum--;
      if (sum < 0) {
        right++;
        sum = 0;
      }
    }
    left = sum;
    vector<string> res;
    // cout<<left<<' '<<right<<endl;
    dfs(s, left, right, res,0);
    return res;
  }
  void dfs(string s, int left, int right, vector<string>& res, int index) {
    if (left == 0 && right == 0 && judge(s)) {
      res.push_back(s);
      return;
    }
    if(left<0||right<0)return;
    for (int i = index; i < s.size(); i++) {
      if (s[i] != '(' && s[i] != ')') continue;
      if(i!=0&&s[i]==s[i-1])continue;
      string tmp = s;
      tmp.erase(i,1);
      if(right>0&&s[i]==')')dfs(tmp,left,right-1,res,i);
      if(left>0&&s[i]=='(')dfs(tmp,left-1,right,res,i);
    }
  }
  bool judge(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        sum++;
      else if (s[i] == ')')
        sum--;
      if (sum < 0) return false;
    }
    return sum == 0;
  }
};
// @lc code=end
