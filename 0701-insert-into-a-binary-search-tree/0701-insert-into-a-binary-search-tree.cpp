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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur=root;
        TreeNode * insertPos;
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        while(cur){
            // if(!cur->left or !cur->right) break;
                insertPos=cur;
            
            if(val>cur->val) {
                cur=cur->right;
            }
            else {
                cur=cur->left;
            }
            
        }
        
        TreeNode * newNode = new TreeNode(val);
        
        if(val<insertPos->val) insertPos->left = newNode;
        else insertPos->right=newNode;
        
        return root;
    }
};