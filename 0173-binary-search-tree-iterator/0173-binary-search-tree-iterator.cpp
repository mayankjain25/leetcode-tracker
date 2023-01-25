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
class BSTIterator {
    stack<TreeNode *>st;
private:
    void pushNodes(TreeNode *node){
        for(;node!=NULL;st.push(node),node=node->left){}
    }
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        
        TreeNode *tmp = st.top();
        st.pop();
        pushNodes(tmp->right);
        return tmp->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */