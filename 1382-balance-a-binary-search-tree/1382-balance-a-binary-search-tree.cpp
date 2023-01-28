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
    void inorder(TreeNode *root, vector<int>&in){
        if(root==NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    
    
    TreeNode* makeTree(vector<int>&in, int start, int end){
        
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode * node = new TreeNode(in[mid]);
        node->left = makeTree(in,start,mid-1);
        node->right=makeTree(in,mid+1,end);
        
        return node;
        
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        return makeTree(in, 0,in.size()-1);
        
        
    }
};