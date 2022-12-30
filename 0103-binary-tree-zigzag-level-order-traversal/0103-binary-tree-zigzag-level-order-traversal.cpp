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
        bool leftToRight=true;
        int index=1;
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            
            vector<int>temp(n);
            
            for(int i=0;i<n;i++){
                TreeNode *node = q.front();
                
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                
                int pushIndex = leftToRight? i: n - i -1;
                temp[pushIndex] = node->val;
                q.pop();
            }
            
          
            
            ans.push_back(temp);
            leftToRight = !leftToRight;
            index++;
        }
        
        return ans;
    }
};