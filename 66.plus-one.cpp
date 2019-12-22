/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.98%)
 * Likes:    908
 * Dislikes: 1611
 * Total Accepted:    410.5K
 * Total Submissions: 991.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int flag=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                flag=(digits[i]+1)/10;
                digits[i]=(digits[i]+1)%10;
            }else{
                int sum=digits[i]+flag;
                flag=sum/10;
                digits[i]=sum%10;
            }
            //cout<<flag<<' '<<digits[i]<<endl;
        }
        if(flag) digits.insert(digits.begin(),flag);
        return digits;
    }
};

