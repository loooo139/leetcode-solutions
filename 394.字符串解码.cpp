/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode-cn.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.18%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 26.5K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 
 * 示例:
 * 
 * 
 * s = "3[a]2[bc]", 返回 "aaabcbc".
 * s = "3[a2[c]]", 返回 "accaccacc".
 * s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int idx=0;
    string decodeString(string s) {
        string res;
        while(idx<s.size()){
            if(s[idx]==']')return res;
            else if(s[idx]>='0'&&s[idx]<='9'){
                int nums=0;
                while(s[idx]>='0'&&s[idx]<='9')nums=nums*10+s[idx++]-'0';
                idx++;
                auto tmp=decodeString(s);
                while(nums--)res+=tmp;
                idx++;
            }
            else res+=s[idx++];
        }
        return res;
    }
};
// @lc code=end

