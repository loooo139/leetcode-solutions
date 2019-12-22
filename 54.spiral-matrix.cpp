/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (30.07%)
 * Likes:    1155
 * Dislikes: 421
 * Total Accepted:    242.8K
 * Total Submissions: 790.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return {};
        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=n-1,up=0,down=m-1;
        vector<int>res;
        while(true){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[up][i]);
            }
            up++;
            if(up>down)break;
            for(int i=up;i<=down;i++)
                res.push_back(matrix[i][right]);
            right--;
            if(right<left)break;
            for(int i=right;i>=left;i--)
                res.push_back(matrix[down][i]);
            down--;
            if(up>down)break;
            for(int i=down;i>=up;i--)
                res.push_back(matrix[i][left]);
            left++;
            if(left>right)break;
        }
        return res;
    }
};

