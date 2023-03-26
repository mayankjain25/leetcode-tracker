//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indegree(V,0), topo;
        
        for(int i=0;i<V;i++){
            for(auto node:adj[i]) indegree[node]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++) if(indegree[i]==0) q.push(i);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        // cout<<topo.size()<<endl<<V<<endl<<endl;
        return topo.size()<(V-1);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends