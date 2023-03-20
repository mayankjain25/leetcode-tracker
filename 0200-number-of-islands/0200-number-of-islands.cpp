class Solution {
public:

    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<bool>>&vis){
        vis[row][col] = true;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size(), m = grid[0].size();


        while(!q.empty()){
            auto val = q.front();
            q.pop();

            vector<int>delrow = {-1,0,1,0},delcol = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int nr = val.first + delrow[i];
                int nc = val.second + delcol[i];

                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc]=='1'){
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    vis[i][j]=true;
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};