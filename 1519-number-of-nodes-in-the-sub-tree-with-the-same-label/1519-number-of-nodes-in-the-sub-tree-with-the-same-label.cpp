class Solution {
public:
    
    void fun(int node, int prevNode, string &labels,vector<int>&freq, unordered_map<int,vector<int>>&adj, vector<int>&ans){
        int prevCount = freq[labels[node]-'a'];
        freq[labels[node]-'a']+=1;
        
        for(auto nextNode: adj[node]){
            if (prevNode==nextNode) continue;
            fun(nextNode,node,labels,freq,adj,ans);
        }
        
        ans[node] = freq[labels[node]-'a'] - prevCount;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>freq(26,0);
        
        vector<int>ans(labels.size());
        
        fun(0,0,labels,freq,adj,ans);
        
        return ans;
    }
};