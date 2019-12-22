/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (55.89%)
 * Likes:    680
 * Dislikes: 86
 * Total Accepted:    50.7K
 * Total Submissions: 87.8K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 * 
 * 
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * 
 * Input: S = "12345"
 * Output: ["12345"]
 * 
 * 
 * Note:
 * 
 * 
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 * 
 * 
 */
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>res;
        dfs(res,S,0);
        return res;
    }
    void dfs(vector<string>&res,string S,int index){
        if(index==S.size()){
            res.push_back(S);
            return ;
        }
        dfs(res,S,index+1);
        if(S[index]>='A'&&S[index]<='z'){
            S[index]=S[index]^32;
            dfs(res,S,index+1);
        }
    }
};

