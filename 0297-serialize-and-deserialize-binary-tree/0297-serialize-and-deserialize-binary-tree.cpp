/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // string serial="",deserial="";
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        
        string serial="";
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node==NULL) serial.append("#,");
            else{
                serial.append(to_string(node->val)+',');
                q.push(node->left);
                q.push(node->right);
            }
            
          
            
        }
        
        cout<<serial;
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node=q.front();
            
            q.pop();
            
            getline(s,str,',');
            if(str!="#"){
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            else node->left=NULL;
            
            getline(s,str,',');
            if(str!="#"){
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
            else node->right=NULL;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));