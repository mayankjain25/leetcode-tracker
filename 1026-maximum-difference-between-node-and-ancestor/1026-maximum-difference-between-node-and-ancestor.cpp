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
 int maxDiff(TreeNode *ptr, int maxi, int mini){
     if(!ptr) return maxi-mini;
     maxi=max(maxi, ptr->val);
     mini=min(mini, ptr->val);
     return max(maxDiff(ptr->left,maxi,mini),maxDiff(ptr->right, maxi,mini));
 }   
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN,mini=INT_MAX;
        return maxDiff(root,maxi,mini);
        
    }
};