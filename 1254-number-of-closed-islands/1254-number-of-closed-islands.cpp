class Solution {
private:
    bool bfs(int row, int col, vector<vector<bool>>&vis, vector<vector<int>>&grid){
        vis[row][col] = true;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n  = grid.size(), m = grid[0].size();

        bool closed = true;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            vector<int>delrow = {-1,0,1,0};
            vector<int>delcol={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nr = node.first + delrow[i];
                int nc = node.second + delcol[i];
                if(nr<0 or nc<0 or nr>=n or nc>=m) closed = false;
                else if(nr>=0 and nc>=0 and  nr<n and nc<m and !vis[nr][nc] and grid[nr][nc]==0)
                {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }

        return closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n  = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int ans = 0;
        int cornerIslands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!vis[i][j] && grid[i][j]==0 and bfs(i,j,vis,grid)){
                    ans++;
                }
           }
        }

        // cout<<cornerIslands<<" "<<ans<<endl;

        return ans;
    }






    // [0,0,1,1,0,1,0,0,1,0]
    // [1,1,0,1,1,0,1,1,1,0]
    // [1,0,1,1,1,0,0,1,1,0]
    // [0,1,1,0,0,0,0,1,0,1]
    // [0,0,0,0,0,0,1,1,1,0]
    // [0,1,0,1,0,1,0,1,1,1]
    // [1,0,1,0,1,1,0,0,0,1]
    // [1,1,1,1,1,1,0,0,0,0]
    // [1,1,1,0,0,1,0,1,0,1]
    // [1,1,1,0,1,1,0,1,1,0]




};