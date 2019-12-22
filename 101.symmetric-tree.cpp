/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSymmetricRe(root->left, root->right);
    }
    bool isSymmetricRe(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetricRe(left->right, right->left) && isSymmetricRe(left->left, right->right);
    }
};
