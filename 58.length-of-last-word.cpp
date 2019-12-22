/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.22%)
 * Likes:    391
 * Dislikes: 1642
 * Total Accepted:    277.8K
 * Total Submissions: 860.6K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0,tmp=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                tmp=0;
            }
            else
            {   
                if(tmp==0){
                    res=tmp;
                    tmp=1;
                }
                res++;
            }
            
        }
        return res;
    }
};

