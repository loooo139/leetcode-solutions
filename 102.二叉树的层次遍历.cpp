/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (59.96%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 112.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *p;
        while(!q.empty()){
            vector<int>tmp;
            int len=q.size();
            for(int i=0;i<len;i++){
                p=q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            res.push_back(tmp);
            
        }
        return res;
    }
};
// @lc code=end

