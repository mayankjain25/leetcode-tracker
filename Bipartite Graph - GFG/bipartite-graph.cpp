//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int start, vector<int>adj[], vector<int>&vis){
        queue<int>q;
        q.push({start});
        vis[start] = 0;
        
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            
            for(auto node:adj[val]){
                if(vis[node]==-1){
                    vis[node] = !vis[val];
                    q.push(node);
                }
                else if(vis[node]!=-1){
                    if(vis[node]==vis[val]) return false;
                }
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int start = 0;
	    vector<int>vis(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1 and bfs(i,adj,vis)==false) return false;
	    }
	    
	    return true;
	}
	

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends