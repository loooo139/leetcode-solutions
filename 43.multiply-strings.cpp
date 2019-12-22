/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.34%)
 * Likes:    1035
 * Dislikes: 476
 * Total Accepted:    207.5K
 * Total Submissions: 670.7K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int m=num1.size(),n=num2.size();
        vector<int>vals(m+n);
        for(int  i=m-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                int val=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=i+j+1,sum=val+vals[p2];
                vals[p1]+=sum/10;
                vals[p2]=sum%10;
            }

        for(int i:vals)
            if(!res.empty()||i!=0)res.push_back(i+'0');
        return res.empty()?"0":res;
    }
};

