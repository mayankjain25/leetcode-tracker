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
    vector<int>inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        TreeNode *node = root;
        // s.push(node);
        while(true){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()) break;
                node=s.top();
                ans.push_back(node->val);
                node=node->right;
                s.pop();
            }
        }
        return ans;
    }
};