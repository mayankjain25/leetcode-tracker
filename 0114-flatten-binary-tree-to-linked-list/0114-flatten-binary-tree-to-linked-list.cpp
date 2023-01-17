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

private:
    void preorder(TreeNode * root, vector<int>&pre){
        if(root==NULL) return;
        
        pre.emplace_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
}
public:
    void flatten(TreeNode* root) {
        
        vector<int>pre;
        
        preorder(root,pre);
        

        
        TreeNode * node=root;
        // node->left=NULL;
        
        for(int i=1;i<pre.size();i++){
            TreeNode * newNode = new TreeNode(pre[i]);
            node->right=newNode;
            node->left=NULL;
            node=node->right;
        }
        
    }
};