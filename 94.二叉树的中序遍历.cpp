/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.26%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    90.8K
 * Total Submissions: 130.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root)return res;
        stack<TreeNode*>st;
        auto p=root;
        while(!st.empty()||p){
            if(p){
                st.push(p);
                p=p->left;
            }
            else{
                p=st.top();
                st.pop();
                res.push_back(p->val);
                p=p->right;
            }
        }
        return res;
    }
};
// @lc code=end

