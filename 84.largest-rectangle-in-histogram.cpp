/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (30.46%)
 * Total Accepted:    162.3K
 * Total Submissions: 532.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution
{
  public:
   /**
    * @brief  本质是寻找每个柱形条左边和右边比自己低的矩形条，左边的第一个低的位置是栈顶，右边是i。
    * @note   
    * @param  &heights: 
    * @retval 
    */
   */
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.empty())
            return 0;
        heights.push_back(-1);
        stack<int> st;
        int i = 0, res = INT_MIN;
        while (i < heights.size())
        {
            if (st.empty() || heights[i] > heights[st.top()])
                st.push(i++);
            else
            {
                auto t = st.top();
                st.pop();
                res = max(res, heights[t] * (st.empty() ? i : i - st.top() - 1));
                //本题目得关键点在于矩形长度得选取，可以看到当取出栈顶位置，得到得是目前最小得高度，然后出栈。此时栈顶元素是比当前高度小得矩形块位置，即左边界，i也为比当前矩形块小得位置，即右边界。两者之差即为所求得长度。
            }
        }
        return res;
    }
};
