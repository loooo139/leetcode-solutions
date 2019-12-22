/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.53%)
 * Likes:    899
 * Dislikes: 68
 * Total Accepted:    230K
 * Total Submissions: 497.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string path;
        if (root == nullptr)
            return res;
        DFS(res, path, root);
        return res;
    }
    void DFS(vector<string> &res, string path, TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        int val = node->val;
        if (path.size() != 0)
            path += "->";
        path += to_string(val);
        if(!node->left&&!node->right)res.push_back(path);
        else{
            DFS(res,path,node->left);
            DFS(res,path,node->right);
        }
    }
};
