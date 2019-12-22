/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.61%)
 * Likes:    1020
 * Dislikes: 198
 * Total Accepted:    315.1K
 * Total Submissions: 794.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int flag=0,m=a.size(),n=b.size(),i=m-1,j=n-1;
        string res;
        while(i>=0&&j>=0){
            int sum=a[i--]-'0'+b[j--]-'0'+flag;
            flag=sum/2;
            res=to_string(sum%2)+res;
        }
        while(i>=0){
            int sum=a[i--]-'0'+flag;
            flag=sum/2;
            res=to_string(sum%2)+res;
        }
        while(j>=0){
            int sum=b[j--]-'0'+flag;
            flag=sum/2;
            res=to_string(sum%2)+res;
        }
        if(flag) res=to_string(flag)+res;
        return res;
    }
};

