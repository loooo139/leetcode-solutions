/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty())
        {
            vector<int> t;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                auto temp = q.front();
                q.pop();
                t.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            res.push_back(t);
        }
        return res;
    }
};
