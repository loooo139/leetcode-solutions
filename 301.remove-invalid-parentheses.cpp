/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (38.89%)
 * Likes:    1515
 * Dislikes: 67
 * Total Accepted:    132.3K
 * Total Submissions: 333.7K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 * 
 * Example 1:
 * 
 * 
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ")("
 * Output: [""]
 * 
 */
class Solution
{
public:
    // vector<string> removeInvalidParentheses(string s)
    // {
    //     int l = 0, r = 0;
    //     for (auto p : s)
    //     {
    //         if (p == '(')
    //             l++;
    //         else if (p == ')')
    //         {
    //             if (l == 0)
    //                 r++;
    //             else
    //                 l--;
    //         }
    //     }
    //     vector<string> res;
    //     // cout<<l<<' '<<r<<endl;
    //     dfs(s, 0, l, r, res);
    //     return res;
    // }
    // bool isValid(string s)
    // {
    //     int cnt = 0;
    //     for (auto i : s)
    //     {
    //         if (i == '(')
    //             cnt++;
    //         if (i == ')')
    //         {
    //             cnt--;
    //             if (cnt < 0)
    //                 return false;
    //         }
    //     }
    //     return cnt == 0;
    // }
    // void dfs(string s, int index, int l, int r, vector<string> &res)
    // {
    //     if (l == 0 && r == 0 && isValid(s))
    //     {
    //         res.push_back(s);
    //         return;
    //     }
    //     if (l < 0 || r < 0)
    //         return;
    //     for (int i = index; i < s.size(); i++)
    //     {
    //         if (i != 0 && s[i] == s[i - 1])
    //             continue;
    //         if (s[i] == '(' || s[i] == ')')
    //         {
    //             string cur = s;
    //             cur.erase(i, 1);
    //             if (s[i] == ')')
    //                 dfs(cur, i, l, r - 1, res);
    //             if (s[i] == '(')
    //                 dfs(cur, i, l - 1, r, res);
    //         }
    //     }
    // }
    vector<string> removeInvalidParentheses(string s){
        int l=0,r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')l++;
            else if(s[i]==')'){
                if(l==0)r++;
                else l--;
            }
        }
        vector<string>res;
        dfs(s,l,r,res,0);
        return res;
    }
    void dfs(string s,int l,int r,vector<string>&res,int pos){
        // cout<<l<<' '<<r<<' '<<s<<endl;
        if(l==0&&r==0&&isValid(s)){
            res.push_back(s);
            return ;
        }
        if(l<0||r<0)return ;
        for(int i=pos;i<s.size();i++){
            if(i!=0&&s[i]==s[i-1])continue;
            if(s[i]=='('||s[i]==')'){
                auto cur=s;
                cur.erase(i,1);
                if(s[i]==')')dfs(cur,l,r-1,res,i);
                if(s[i]=='(')dfs(cur,l-1,r,res,i);

            }
        }
    }
    bool isValid(string s){
        int num=0;
        for(auto i:s){
            if(i=='(')num++;
            else if(i==')') num--;
            if(num<0)return false;
        }
        return num==0;
    }
};
