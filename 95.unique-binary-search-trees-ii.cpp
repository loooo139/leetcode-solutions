/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (35.28%)
 * Likes:    1257
 * Dislikes: 113
 * Total Accepted:    140.9K
 * Total Submissions: 392.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
        return divide(1,n);
    }
    vector<TreeNode*>divide(int start,int end){
        if(start>end)return{nullptr};
        vector<TreeNode*>res;
        for(int i=start;i<=end;i++){
            auto left=divide(start,i-1),right=divide(1+i,end);
            for(auto a:left)
                for(auto b:right){
                    TreeNode *node=new TreeNode(i);
                    node->left=a;
                    node->right=b;
                    res.push_back(node);
                }
        }
        return res;
    }
};

