/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (69.13%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    44K
 * Total Submissions: 63.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        TreeNode *p;
        p=root;
        while(!st.empty()||p){
            if(p){
                st.push(p);
                res.push_back(p->val);
                p=p->right;
            }
            else{
                p=st.top();
                st.pop();
                p=p->left;
            }
        }
        return vector<int>(res.rbegin(),res.rend());
    }
};
// @lc code=end

