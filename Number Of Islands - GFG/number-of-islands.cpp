//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int>parent, size;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
        
        int findUltimateParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]); //path compression
    }

    void unionBySize(int u, int v){
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if(pu==pv) return;
        
        if(size[pu]<size[pv]){
            parent[pu] = parent[pv];
            size[pv] +=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
        
};

class Solution {
  private:
  bool isValid(int adjr, int adjc, int n, int m){
      return adjr>=0 and adjr<n and adjc>=0 and adjc<m;
  }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        // vector<vector<int>>grid(n, vector<int>(m,0));
        DisjointSet ds(n*m);
        
        vector<vector<int>>vis(n, vector<int>(m,0));
        int currCount = 0;
        vector<int>ans;
        
        for(auto it:operators){
            int row = it[0], col = it[1];
            if(vis[row][col]){
                ans.push_back(currCount);
                continue;
            }
            else{
                vis[row][col] = 1;
                currCount++;
                vector<int>delrow = {-1,0,1,0}, delcol = {0,1,0,-1};
                
                for(int i=0;i<4;i++){
                    int newRow = row + delrow[i];
                    int newCol = col + delcol[i];
                    
                    if(isValid(newRow, newCol, n, m)){
                        if(vis[newRow][newCol]){
                            int nodeCell = row * m + col;
                            int adjNodeCell = newRow * m + newCol;
                            
                            if(ds.findUltimateParent(nodeCell)!=ds.findUltimateParent(adjNodeCell)){
                                ds.unionBySize(adjNodeCell, nodeCell);
                                currCount--;
                                
                            }
                        }
                    }
                }
                ans.push_back(currCount);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends