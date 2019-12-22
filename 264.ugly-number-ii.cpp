/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> res(n);
        if (n <= 0)
            return -1;
        res[0] = 1;
        int index = 1;
        int ugly2 = 0, ugly3 = 0, ugly5 = 0;
        while (index < n)
        {
            int minValue = min(res[ugly2] * 2, min(res[ugly3] * 3, res[ugly5] * 5));
            res[index++] = minValue;
            while (res[ugly2] * 2 <= minValue)
                ugly2++;
            while (res[ugly3] * 3 <= minValue)
                ugly3++;
            while (res[ugly5] * 5 <= minValue)
                ugly5++;
        }
        return res.back();
    }
};
