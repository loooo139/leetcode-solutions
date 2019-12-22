/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (42.06%)
 * Likes:    1846
 * Dislikes: 51
 * Total Accepted:    237.3K
 * Total Submissions: 564.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    unordered_map<int,int>inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            inorderMap[inorder[i]]=i;
        }
        return dfs(preorder,inorder,0,n-1,0,n-1);
    }
    TreeNode*dfs(vector<int>&preorder,vector<int>&inorder,int pl,int pr,int il,int ir){
        if(pl>pr)return nullptr;
        TreeNode *node=new TreeNode(preorder[pl]);
        int k=inorderMap[preorder[pl]]-il;
        node->left=dfs(preorder,inorder,pl+1,pl+k,il,il+k-1);
        node->right=dfs(preorder,inorder,pl+k+1,pr,il+k+1,ir);
        return node;
    }
};

