/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        auto *p = root;
        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            }
            else
            {
                auto t = s.top();
                s.pop();
                p = t->left;
            }
        }
        return res;
    }
};
