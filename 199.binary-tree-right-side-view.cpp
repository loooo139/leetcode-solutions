/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (50.63%)
 * Likes:    1481
 * Dislikes: 78
 * Total Accepted:    215.5K
 * Total Submissions: 425K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 */

// @lc code=start
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        dfs(root,res,0);
        return res;
    }
    void dfs(TreeNode * node,vector<int>&res,int pos){
        if(!node)return;
        if(res.size()==pos){
            res.push_back(node->val);
        }
        dfs(node->right,res,pos+1);
        dfs(node->left,res,pos+1);
        return ;
    }
};
// @lc code=end

