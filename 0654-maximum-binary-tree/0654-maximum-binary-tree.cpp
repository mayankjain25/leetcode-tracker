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
    TreeNode * buildTree(vector<int>&nums, int startPointer,int endPointer){
        if(startPointer==nums.size() or endPointer<0 or startPointer>endPointer) return NULL;
        
        int maxPointer = max_element(nums.begin()+startPointer,nums.begin()+endPointer+1) - nums.begin();
        cout<<maxPointer<<endl;
        TreeNode * root = new TreeNode(nums[maxPointer]);
        root->left = buildTree(nums, startPointer, maxPointer-1 );
        root->right = buildTree(nums, maxPointer+1, endPointer);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        
        
        return buildTree(nums, 0,nums.size()-1);
        
    }
};

// 1) find maximum point
// 2) create root from that maximum point
// 3) the left of this root will be part of left subtree
// 4) the right of this root will be part of right subtree