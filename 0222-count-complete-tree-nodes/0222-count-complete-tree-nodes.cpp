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
    int maxDepth(TreeNode *root){
        if(root==NULL) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    
    bool isLeaf(TreeNode *node){
        return node->left==NULL and node->right==NULL;
    }
    void countLeaf(TreeNode*root, int &count,int level,int height){
        if(root==NULL) return;
        if(isLeaf(root) and level==height) count++;
        level++;
        if(root->left) countLeaf(root->left,count,level,height);
        if(root->right) countLeaf(root->right,count,level,height);
    }
    int countNodes(TreeNode* root) {
        int height=maxDepth(root);
        if(height==0) return 0;
        int val=(1<<(height-1)) -1;
        int cnt=0;
        countLeaf(root,cnt,1,height);
        cout<<height<<" "<<cnt<<endl;
        return val +cnt;
    }
};