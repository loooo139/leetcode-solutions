/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (25.52%)
 * Likes:    1995
 * Dislikes: 297
 * Total Accepted:    415.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
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
 /**
  * @brief  
  * @note   
  * @param  root: 
  * @retval 
  */
    bool isValidBST_inorder(TreeNode* root) {
        stack<TreeNode*>que;
        if(root==nullptr)return true;
        TreeNode *q=root;
        vector<int>res;
        while(q||!que.empty()){
            if(q){
                que.push(q);
                q=q->left;
            }
            else{
                q=que.top();
                que.pop();
                if(!res.empty()&&res.back()>=q->val)
                    return false;
                res.push_back(q->val);
                q=q->right;
            }
        }
        return true;
        }
    bool isValidBST(TreeNode* root){

        return dfs(root,INT_MIN,INT_MAX);
    }
    bool dfs(TreeNode *root,long minv,long maxv){
        if(root==nullptr)return true;
        if(root->val<minv||root->val>maxv)return false;
        return dfs(root->left,minv,root->val-1ll)&&dfs(root->right,root->val+1ll,maxv);
    }
};

