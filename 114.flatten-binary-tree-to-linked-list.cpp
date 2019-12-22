/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (45.32%)
 * Likes:    1964
 * Dislikes: 256
 * Total Accepted:    282.8K
 * Total Submissions: 623.8K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
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
/**
 * @brief  中序遍历，找到当前节点的前序节点，中序：左中右，目标要求中左右。则中序的前序节点的下一节点为当前的右子节点。
 * @note   
 * @retval None
 */
class Solution_1 {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left){
                auto p=root->left;
                while(p&&p->right)p=p->right;
                p->right=root->right;
                root->right=root->left;
                root->left=nullptr;
            }
            root=root->right;
        }
    }
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            if(p->right)st.push(p->right);
            if(p->left)st.push(p->left);
            p->right=st.empty()?nullptr:st.top();
            p->left=0;
        }
    }
};
// @lc code=end

