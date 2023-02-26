class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<bool>>&vis){
        vis[row][col] = true;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size(), m = grid[0].size();


        while(!q.empty()){
            auto val = q.front();
            q.pop();

            //traversing the four directions
            
             for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol=-1;deltacol<=1;deltacol++){
                    if((deltarow==-1 and deltacol==-1) or (deltarow==-1 and deltacol==1) or (deltarow==1 and deltacol==-1) or (deltarow==1 and deltacol==1))
                    continue;

                    int nr=val.first+deltarow;
                    int nc=val.second+deltacol;
                    if(nr>=0 and nc>=0 and nr<n and nc<m and !vis[nr][nc] and grid[nr][nc]=='1'){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
           

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==false){
                    ans++;

                    bfs(i,j,grid,vis);
                }
            }
        }

        for(auto it:vis){
            for(auto it1:it) cout<<it1<<" ";
            cout<<endl;
        }

        return ans;
    }
};






