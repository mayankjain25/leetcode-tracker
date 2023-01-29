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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode *>q;
        if(root==NULL) return 0;
        q.push(root);
        
        while(!q.empty()){
            sum=0;
            int n = q.size();
            for(int i=1;i<=n;i++){
                TreeNode * ptr = q.front();
                q.pop();
                sum+=ptr->val;
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
        }
        
        return sum;
    }
};