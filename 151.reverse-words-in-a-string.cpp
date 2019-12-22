/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (16.38%)
 * Likes:    570
 * Dislikes: 2289
 * Total Accepted:    286.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */
class Solution {
public:
     /**
      * @brief  
      * @note   
      * @param  s: 
      * @retval 
      */
    // string reverseWords(string s) {
    //     istringstream is(s);
    //     string tmp;
    //     s="";
    //     is>>s;
    //     while(is>>tmp)s=tmp+" "+s;
    //     //if(s.size()&&s[0]==' ') s="";
    //     return s;
    // }
    string reverseWords(string s){
        int indexStore=0,n=s.size();
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                if(indexStore!=0)s[indexStore++]=' ';
                int j=i;
                while(j<n&&s[j]!=' ')s[indexStore++]=s[j++];
                reverse(s.begin()+indexStore-(j-i),s.begin()+indexStore);
                i=j;
            }
        }
        s.resize(indexStore);
        return s;
    }
};

