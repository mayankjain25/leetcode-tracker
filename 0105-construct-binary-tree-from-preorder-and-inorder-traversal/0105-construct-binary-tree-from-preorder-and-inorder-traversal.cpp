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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inHash;
        
        for(int i=0;i<inorder.size();i++){
            inHash[inorder[i]]=i;
        }
        
        TreeNode * root = makeTree(preorder, 0, preorder.size()-1,inorder,0,inorder.size()-1,inHash);
        
        return root;
    }
    
    TreeNode* makeTree(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, unordered_map<int,int>&inHash){
        if(preStart>preEnd or inStart>inEnd) return NULL;
        
        TreeNode * root=new TreeNode(preorder[preStart]);
        int inorderRootPosition=inHash[preorder[preStart]];
        int numsLeft = inorderRootPosition - inStart;
        
        root->left=makeTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart,inorderRootPosition-1,inHash);
        root->right=makeTree(preorder,preStart+numsLeft+1,preEnd,inorder,inorderRootPosition+1,inEnd,inHash);
        
        return root;
        
    }
};