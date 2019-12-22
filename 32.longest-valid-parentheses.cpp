/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.23%)
 * Likes:    1913
 * Dislikes: 91
 * Total Accepted:    195.4K
 * Total Submissions: 761K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0,left=0;
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    left=i+1;
                }
                else{
                    st.pop();
                    res=st.empty()?max(res,i-left+1):max(res,i-st.top());
                }
            }
        }
        return res;
    }
};

