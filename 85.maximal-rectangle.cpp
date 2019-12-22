/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (32.89%)
 * Total Accepted:    117.5K
 * Total Submissions: 356.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        vector<int> height;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res=max(res,maxRectangle(height));
        }
        return res;
    }
    int maxRectangle(vector<int>height){
        height.push_back(-1);
        int n=height.size();
        stack<int>st;
        int res=0;
        for(int i=0;i<n;){
            if(st.empty()||height[st.top()]<=height[i])st.push(i++);
            else{
                int t=st.top();st.pop();
                res=max(res,height[t]*(st.empty()?i:i-st.top()-1));
            }
        }
        return res;
    }
};

