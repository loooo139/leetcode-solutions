/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (41.38%)
 * Likes:    1006
 * Dislikes: 36
 * Total Accepted:    248.6K
 * Total Submissions: 595.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>path;
        dfs(res,path,root,sum);
        return res;
    }
    void dfs(vector<vector<int>>&res,vector<int>&path,TreeNode * node,int sum){
        if(!node)return ;
        path.push_back(node->val);
        if(node->val==sum&&!node->left&&!node->right){
            res.push_back(path);
        }
        dfs(res,path,node->left,sum-node->val);
        dfs(res,path,node->right,sum-node->val);
        path.pop_back();
        return;
    }
};

