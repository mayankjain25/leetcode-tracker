//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>&grid, vector<vector<bool>>&vis, set<vector<pair<int,int>>>&s, pair<int,int>&p){
        vis[row][col] = true;
        vector<pair<int,int>>temp;
        temp.push_back({row - p.first, col - p.second});
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size(), m = grid[0].size();
        
        
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            
            vector<int>delrow = {-1,0,1,0}, delcol = {0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nr = val.first + delrow[i];
                int nc = val.second + delcol[i];
                
                if(nr>=0 and nr<n and nc >=0 and nc<m and !vis[nr][nc] and grid[nr][nc]==1){
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                    temp.push_back({nr - p.first, nc  - p.second});
                }
            }
            
            
        }
        
        s.insert(temp);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        set<vector<pair<int,int>>>s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pair<int,int> p = {i,j};
                if(grid[i][j]==1 and !vis[i][j]){
                    bfs(i,j,grid,vis,s,p);
                }
            }
        }
        
        
        
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends