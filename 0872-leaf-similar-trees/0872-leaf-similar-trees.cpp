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
void leafGenerator(TreeNode *root, string &s1){
    if(root==NULL) return;
    if(!root->left and !root->right){
        s1+=root->val;
        s1+='#';
    }
    leafGenerator(root->left,s1);
    leafGenerator(root->right,s1);
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        leafGenerator(root1,s1);
        leafGenerator(root2,s2);
        return s1==s2;
    }
};