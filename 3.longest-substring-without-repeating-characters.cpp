/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.08%)
 * Total Accepted:    842.7K
 * Total Submissions: 3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
class Solution
{
public:
    /**
     * @brief  第一种方法滑动窗口+hashmap
     * @note   
     * @param  s: 
     * @retval 
     */
    // int lengthOfLongestSubstring(string s)
    // {
    //     if (s.empty())
    //         return 0;
    //     vector<int> map(256, -1);
    //     int left = -1, res = INT_MIN;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         left = max(left, map[s[i]]);
    //         map[s[i]] = i;
    //         res = max(res, i - left);
    //     }
    //     return res;
    // }
    /**
     * @brief  第二种方法 动态规划
     * @note   
     * @param  s: 
     * @retval 
     */
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(256, -1);
        if (s.empty())
            return 0;
        int res = INT_MIN;
        int curLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 || curLength + dict[s[i]] < i)
                curLength++;
            else
            {
                curLength = i - dict[s[i]];
            }
            res = max(res, curLength);
            dict[s[i]] = i;
        }
        return res;
    }
};
