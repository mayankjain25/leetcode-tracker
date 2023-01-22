/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:  
    bool helper(TreeNode *root,long lower, long higher){
        if(root==NULL) return true;
        if(root->val >=higher or root->val<=lower) return false;
        bool left=helper(root->left,lower,root->val);
        bool right=helper(root->right,root->val,higher);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN,LONG_MAX);
    }
};