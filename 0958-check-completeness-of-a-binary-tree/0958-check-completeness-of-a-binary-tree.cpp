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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        bool val = true;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node==NULL) val = false;
            else{
                if(val==false) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};