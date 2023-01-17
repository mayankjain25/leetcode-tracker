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
TreeNode *prev=NULL;
public:
    void flatten(TreeNode* root) {
       stack<TreeNode*>st;
        
        if(root==NULL) return;
        st.push(root);
        
    
        
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            if(!st.empty()) node->right=st.top();
            node->left=NULL;
        }
    }
};