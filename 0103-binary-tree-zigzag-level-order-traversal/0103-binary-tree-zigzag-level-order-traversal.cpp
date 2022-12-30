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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        int index=1;
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            
            vector<int>temp;
            
            for(int i=0;i<n;i++){
                TreeNode *node = q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                temp.push_back(node->val);
                q.pop();
            }
            
            if(!(index&1)){
                reverse(temp.begin(),temp.end());
            }
            
            ans.push_back(temp);
            index++;
        }
        
        return ans;
    }
};