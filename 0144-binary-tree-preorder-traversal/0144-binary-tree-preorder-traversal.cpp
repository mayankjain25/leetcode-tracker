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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
       stack<TreeNode*>s;
        
        if(root==NULL) return ans;
        s.push(root);
        
        
        while(!s.empty()){
            TreeNode *ptr = s.top();
            s.pop();
            
            if(ptr->right) s.push(ptr->right);
            if(ptr->left) s.push(ptr->left);
            ans.push_back(ptr->val);
        }
        
        return ans;
    }
};