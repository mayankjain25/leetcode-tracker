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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inorderHash;
        
        for(int i=0;i<inorder.size();i++) inorderHash[inorder[i]]=i;
        
        TreeNode *root = makeTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inorderHash);
        
        return root;
    }
    
    TreeNode* makeTree(vector<int>&postorder, int postStart, int postEnd, vector<int>&inorder, int inStart, int inEnd, unordered_map<int,int>&inorderHash){
        if(postEnd<postStart or inStart>inEnd or postStart<0) return NULL;
        
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int inRoot=inorderHash[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left=makeTree(postorder, postStart, postStart+numsLeft -1,inorder,inStart,inRoot-1,inorderHash);
        root->right=makeTree(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,inorderHash);
        
        return root;
    }
};