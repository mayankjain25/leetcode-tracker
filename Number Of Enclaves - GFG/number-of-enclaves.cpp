//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        vis[row][col] = true;
        int n = grid.size(),m = grid[0].size();
        
        vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr = row + delrow[i];
            int nc=  col + delcol[i];
            
            if(nr>=0 and nc>=0 and nr<n and nc<m and !vis[nr][nc] and grid[nr][nc]==1) dfs(nr,nc,grid,vis);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 and !vis[0][i]) dfs(0,i,grid,vis);
            if(grid[n-1][i]==1 and !vis[n-1][i]) dfs(n-1,i,grid,vis);
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 and !vis[i][m-1]) dfs(i,m-1,grid,vis);
            if(grid[i][0]==1 and !vis[i][0]) dfs(i,0,grid,vis);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1) ans++;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends