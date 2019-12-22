/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1.0, tmp = x;
        bool flag = n > 0 ? true : false;
        while (n)
        {
            if (n & 1 == 1)
                res *= tmp;
            tmp *= tmp;
            n /= 2;
        }
        return flag ? res : 1 / res;
    }
};
