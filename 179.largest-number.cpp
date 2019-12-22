/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> res(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = to_string(nums[i]);
        }
        sort(res.begin(), res.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        string s;
        for (auto i : res)
            s = s + i;
        return res[0] == "0" ? "0" : s;
    }
};
