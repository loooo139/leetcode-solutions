/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (41.19%)
 * Likes:    979
 * Dislikes: 60
 * Total Accepted:    224.8K
 * Total Submissions: 535K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr)return res;
        queue<TreeNode*>que;
        que.push(root);
        bool flag=false;
        while(!que.empty()){
            int len=que.size();
            vector<int>line;
            for(int i=0;i<len;i++){
                auto temp=que.front();
                que.pop();
                line.push_back(temp->val);
                if(temp->left)que.push(temp->left);
                if(temp->right)que.push(temp->right);
            }
            if(flag)
                reverse(line.begin(),line.end());
            flag=!flag;
            res.push_back(line);
        }
        return res;
    }
};

