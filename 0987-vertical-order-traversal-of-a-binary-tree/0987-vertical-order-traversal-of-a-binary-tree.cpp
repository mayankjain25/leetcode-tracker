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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         map<int,map<int,multiset<int>>> nodes; //a map ds to store the nodes vertical wise level-wise
        queue<pair<TreeNode*,pair<int,int>>> todo; // a queue to store the nodes
        
        //pushing the root node, which is considered to be at level 0 and at vertical 0
        todo.push({root,{ 0, 0}});
        
        while(!todo.empty()){
            auto val= todo.front();
            todo.pop();
            
            int vertical = val.second.first;
            int level = val.second.second;
            TreeNode *node = val.first;
            nodes[vertical][level].insert(node->val);
            if(node->left){
                todo.push({node->left,{vertical-1,level+1}});
            }
            if(node->right){
                todo.push({node->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto vertical:nodes){
            vector<int>temp;
            for(auto level:vertical.second){
                temp.insert(temp.end(),level.second.begin(),level.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};