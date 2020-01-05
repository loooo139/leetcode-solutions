/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 *
 * https://leetcode-cn.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (44.48%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 7.6K
 * Testcase Example:  '"ABAB"\n2'
 *
 * 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k
 * 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
 * 
 * 注意:
 * 字符串长度 和 k 不会超过 10^4。
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "ABAB", k = 2
 * 
 * 输出:
 * 4
 * 
 * 解释:
 * 用两个'A'替换为两个'B',反之亦然。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "AABABBA", k = 1
 * 
 * 输出:
 * 4
 * 
 * 解释:
 * 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
 * 子串 "BBBB" 有最长重复字母, 答案为 4。
 * 
 * 
 */
//不清楚的一点就是这个字符是由很多还是就由两种，主要是要计算窗口内出现最多的字符，然后把剩下的字符全部替换，当替换的字符数目大于K的时候，做窗口进行滑动。
// @lc code=start
class Solution {
public:
    int maxValuePos(vector<int>&nums){
        int value=-1;
        int res=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>value){
                value=nums[i];
                //res=i;
            }
        }
        return value;
    }
    int characterReplacement(string s, int k) {
        int res=0;
        vector<int>nums(26,0);
        for(int i=0,j=0;i<s.size();i++){
            nums[s[i]-'A']++;
            int len=maxValuePos(nums);
            if(i-j+1-len<=k){
                res=max(res,i-j+1);
            }
            while(i-j+1-len>k){
                nums[s[j++]-'A']--;
                len=maxValuePos(nums);
            }
        }
        return res;
    }
    
};
// @lc code=end

