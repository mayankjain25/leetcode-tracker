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
    void inorder(TreeNode *root, TreeNode *&ans){
        if(root==NULL) return;
        
        inorder(root->left,ans);
        ans->right= new TreeNode(root->val);
        ans=ans->right;
        inorder(root->right,ans);
        
        
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode * tmp;
        TreeNode *ans = new TreeNode();
        tmp = ans;
        inorder(root,ans);
        return tmp->right;
        
    }
};

 