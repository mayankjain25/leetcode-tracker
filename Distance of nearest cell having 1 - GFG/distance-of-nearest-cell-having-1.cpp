//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<pair<int,int>,int>>q;
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<vector<bool>>vis(n,vector<bool>(m,false));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1) {q.push({{i,j},0});vis[i][j] = true;}
	            
	        }
	    }
	    
	    while(!q.empty()){
	        auto val = q.front();
	        q.pop();
	        
	        int delrow[]={-1,0,1,0};
	        int delcol[]={0,1,0,-1};
	        
	        for(int i=0;i<4;i++){
                int nr = val.first.first + delrow[i];
                int nc = val.first.second + delcol[i];
                if(nr>=0 and nc>=0 and nr<n and nc<m and !vis[nr][nc] ){
                    // cout<<1<<endl;
                    q.push({{nr,nc},val.second+1});
                    vis[nr][nc]=true;
                    ans[nr][nc] = val.second + 1;
                }
	            
	        }
	    }
	    
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends