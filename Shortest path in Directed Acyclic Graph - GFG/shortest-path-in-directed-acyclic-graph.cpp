//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  void topo(int index, vector<pair<int,int>>adj[], vector<int>&vis, stack<int>&st){
      vis[index] = 1;
      
      for(auto node:adj[index]){
          if(!vis[node.first]){
              topo(node.first, adj, vis, st);
          }
      }
      
      st.push(index);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        stack<int>st;
        vector<int>vis(N,0);
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo(i,adj,vis,st);
            }
        }
        
        vector<int>dist(N, INT_MAX);
        dist[0] = 0;
        
        while(st.top()!=0){
            auto node = st.top();
            dist[node] = -1;
            st.pop();
        }
        
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            
            for(auto it:adj[node]){
                int currNodeDist = dist[node];
                int addedWeight = it.second;
                int newNode = it.first;
                
                if(currNodeDist + addedWeight < dist[newNode]){
                    dist[newNode] = currNodeDist + addedWeight;
                }
            }
        }
        
        return dist;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends