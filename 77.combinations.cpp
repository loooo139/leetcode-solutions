/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.92%)
 * Likes:    816
 * Dislikes: 48
 * Total Accepted:    210.6K
 * Total Submissions: 435.3K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>cur;
        dfs(n,k,1,res,cur);
        return res;
    }
    void dfs(int n,int k,int num,vector<vector<int>>&res,vector<int>&cur){
        if(cur.size()==k){
            res.push_back(cur);
            return;
        }
        for(int i=num;i<=n;i++){
            cur.push_back(i);
            dfs(n,k,i+1,res,cur);
            cur.pop_back();
        }
        return;
    }
};

