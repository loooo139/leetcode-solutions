/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        auto p = root;
        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return res;
    }
};