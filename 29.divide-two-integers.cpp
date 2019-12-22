/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.15%)
 * Likes:    693
 * Dislikes: 3282
 * Total Accepted:    200.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        long  m=abs((long long) dividend),n=abs((long long ) divisor),res=0;
        if(m<n)return 0;
        while(m>=n){
            long long t=n,p=1;
            while(m>(t<<1)){
                t<<=1;
                p<<=1;
            }
            res+=p;
            m-=t;
        }
        if((dividend<0)^(divisor<0))res=-res;
        return res>INT_MAX?INT_MAX:res;
    }
};

