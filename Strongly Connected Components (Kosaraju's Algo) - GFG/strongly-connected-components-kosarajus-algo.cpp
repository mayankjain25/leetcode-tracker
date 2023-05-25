//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int start, unordered_map<int, vector<int>>&adj, vector<int>&vis,stack<int> &st){
	    vis[start] = 1;
	    
	    for(auto it:adj[start]){
	        if(!vis[it]) dfs(it, adj, vis,st);
	    }
	    
	    st.push(start);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        unordered_map<int, vector<int>>adjList;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjList[i].push_back(it);
            }
        }
        vector<int>vis(V,0);
        stack<int>st;
        
        //populating the stack
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adjList,vis,st);
            }
        }
        
        //reversing the edges of the graph
        
        adjList.clear();
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjList[it].push_back(i);
            }
        }
        
        vis = vector<int>(V,0);
        
        int ans = 0;
        stack<int>dummy;
        while(!st.empty()){
            auto val = st.top();
            st.pop();
            
            if(!vis[val]){
                ans++;
                dfs(val, adjList,vis, dummy);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends