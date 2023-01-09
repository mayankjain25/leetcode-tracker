/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void trackNodeParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&parentMap){
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if(node->left){
                parentMap[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parentMap[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        trackNodeParents(root, parentMap);
        
        for(auto it:parentMap){
            cout<<it.first->val<<" "<<it.second->val<<endl;
        }
        
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        visited[target]=true;
        q.push(target);
        int currLevel=0;
        while(!q.empty()){
            if(currLevel++==k) break;
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left and !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right and !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentMap[node] and !visited[parentMap[node]]){
                    q.push(parentMap[node]);
                    visited[parentMap[node]]=true;
                }
            }
            
        }
        
        vector<int>result;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            result.push_back(node->val);
        }
        
        return result;
    }
};

