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
void calcRightTraversal(TreeNode*node, vector<int>&ans){
    ans.push_back(node->val);
    if(node->right){
        calcRightTraversal(node->right,ans);
    }
    else if(node->left) calcRightTraversal(node->left,ans);
    else return;
}
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int val=0;
        // ans.push_back(root->val);
        // calcRightTraversal(root, ans);
        while(!q.empty()){
            int n = q.size();
            
            for(int i=1;i<=n;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node ->right);
                val=node->val;
            }
            ans.push_back(val);
        }
        return ans;
    }
};