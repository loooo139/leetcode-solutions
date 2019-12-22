/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.77%)
 * Likes:    885
 * Dislikes: 106
 * Total Accepted:    231.6K
 * Total Submissions: 661.9K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }
        
        if (matrix[r / m][r % m] != target) return false;
        return true;
    }
};

