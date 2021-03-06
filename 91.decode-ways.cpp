/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10")
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
