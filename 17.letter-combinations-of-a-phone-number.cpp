/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.24%)
 * Likes:    2436
 * Dislikes: 325
 * Total Accepted:    425K
 * Total Submissions: 1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>charmap={"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;
        if(digits.size()==0)return res;
        res.push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string>temp;
            int val=digits[i]-'0';
            for(int j=0;j<charmap[val].size();j++){
                for(int k=0;k<res.size();k++){
                    temp.push_back(res[k]+charmap[val][j]);
                }
            }
            res=temp;
        }
        return res;
    }
};

