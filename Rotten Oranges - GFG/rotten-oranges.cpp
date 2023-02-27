//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    void bfs(queue<pair<pair<int,int>,int>>q, vector<vector<int>>&vis, vector<vector<int>>&grid,int &time){
        int n = grid.size(),m = grid[0].size();
        vector<int>delRow = {-1,0,1,0},delCol={0,1,0,-1};
        
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int newRow = val.first.first + delRow[i];
                int newCol = val.first.second + delCol[i];
                
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and grid[newRow][newCol]==1 and vis[newRow][newCol]==-1){
                    vis[newRow][newCol] = 2;
                    q.push({{newRow,newCol},val.second+1});
                    time = max(time, val.second+1);
                }
            }
        }
    }
        
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(),m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        int time = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
        bfs(q,vis,grid,time);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and vis[i][j]!=2) return -1;
            }
        }
        
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends