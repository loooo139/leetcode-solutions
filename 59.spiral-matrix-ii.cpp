/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (45.33%)
 * Total Accepted:    127.7K
 * Total Submissions: 281.7K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int l = 0, r = n - 1, u = 0, d = n - 1;
        for (int num = 1; num <= n * n;)
        {
            for (int i = l; i <= r; i++)
            {
                res[u][i] = num++;
            }
            if (++u > d)
                break;
            for (int i = u; i <= d; i++)
            {
                res[i][r] = num++;
            }
            if (--r < l)
                break;
            for (int i = r; i >= l; i--)
            {
                res[d][i] = num++;
            }
            if (--d < u)
                break;
            for (int i = d; i >= u; i--)
            {
                res[i][l] = num++;
            }
            if (++l > r)
                break;
        }
        return res;
    }
};
