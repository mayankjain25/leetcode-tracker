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
    void inorder(vector<int>&inorderArray, TreeNode *root){
        if(root==NULL) return;
        inorder(inorderArray,root->left);
        inorderArray.push_back(root->val);
        inorder(inorderArray,root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorderArray;
        inorder(inorderArray,root);
        
        int i=0,j=inorderArray.size()-1;
        
        while(i<j){
            int val = inorderArray[i] + inorderArray[j];
            if(val==k) return true;
            if(val<k) i++;
            else j--;
            
        }
        
        return false;
    }
};