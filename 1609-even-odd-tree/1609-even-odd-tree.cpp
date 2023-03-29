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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        
        q.push(root);
        if(!(root->val&1)) return false;
        int counter = 0;

        while(!q.empty()){
            int n = q.size();

            vector<int>temp;

            for(int i=1;i<=n;i++){
                auto val = q.front();
                q.pop();

                if(val->left) q.push(val->left);
                if(val->right) q.push(val->right);

                temp.push_back(val->val);
            }

            if(!counter){
                int prev = temp[0];
                if(prev%2==0) return false;
                for(int i=1;i<temp.size();i++){
                    int value = temp[i];
                    if(value%2==0) return false;
                    else if(value<=prev) return false;
                    prev=value;
                }
            }
            else{
                
                int prev = temp[0];
                if(prev%2!=0) return false;
                for(int i=1;i<temp.size();i++){
                    int value = temp[i];
                    if(value%2!=0) return false;
                    else if(value>=prev) return false;
                    prev=value;
                }
    
            }
            counter=!counter;
        }



        return true;


    }
};