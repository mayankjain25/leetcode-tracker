//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class DisjointSet{
    vector<int>size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++) parent[i] = i;
    }
    
    int findUltimateParent(int u){
        if(parent[u]==u) return u;
        else return parent[u] = findUltimateParent(parent[u]);
    }
    
    void unionBySize(int u, int v){
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu==pv) return;
        
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+= size[pu];
        }
        else{
            parent[pv]=pu;
            size[pv]+=size[pu];
        }
    }
};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>>edges;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int v = it[0];
                int wt = it[1];
                int u = i;
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int ans = 0;
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
                ans+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends