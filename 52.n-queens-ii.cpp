/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (51.36%)
 * Likes:    286
 * Dislikes: 116
 * Total Accepted:    102.1K
 * Total Submissions: 194.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    int totalNQueens(int n) {
        vector<int>pos(n,-1);
        int res=0;
        dfs(pos,0,res);
        return res;
    }
    void dfs(vector<int>&pos,int idx,int &res){
        if(idx==pos.size()){
            res++;
            return ;
        }
        for(int i=0;i<pos.size();i++){
            if(isValid(pos,idx,i)){
                pos[idx]=i;
                dfs(pos,idx+1,res);
                pos[idx]=-1;
            }
        }
    }
    bool isValid(vector<int>&pos,int row,int col){
        for(int i=0;i<row;i++){
            if(pos[i]==col||abs(row-i)==abs(col-pos[i]))return false;
        }
        return true;
    }

};

