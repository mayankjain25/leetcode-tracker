//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        queue<pair<int,pair<int,int>>>q;
        
        if(source==destination) return 0;
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m,1e5));
        
        dist[source.first][source.second] = 0;
        
        q.push({0,source});
        
        while(!q.empty()){
            auto item = q.front();
            q.pop();
            
            int currDist = item.first;
            int currRow = item.second.first;
            int currCol = item.second.second;
            
            vector<int>delrow={-1,0,1,0},delcol = {0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int newRow = currRow + delrow[i];
                int newCol = currCol + delcol[i];
                
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and grid[newRow][newCol]==1 and (currDist + 1 < dist[newRow][newCol]) ){
                        dist[newRow][newCol] = currDist+1;
                        if(newRow==destination.first and newCol==destination.second){
                        return dist[newRow][newCol];
                    }
                        q.push({dist[newRow][newCol],{newRow,newCol}});
                    
                    
                    
                }
            }
            
           
            
        }
            return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends