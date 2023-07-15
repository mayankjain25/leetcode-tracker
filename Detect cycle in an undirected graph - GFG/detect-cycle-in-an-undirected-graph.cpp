//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node] = true;
        queue<pair<int,int>>q;
        q.push({node, -1});
        
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            
            int vertex = val.first;
            int parent = val.second;
            
            for(auto it:adj[vertex]){
                if(vis[it] and it!=parent) return true;
                if(!vis[it])
                {
                    vis[it] = true;
                    q.push({it, vertex});
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends