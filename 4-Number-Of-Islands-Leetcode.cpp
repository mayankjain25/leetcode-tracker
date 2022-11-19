class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            //traversing the 4 directions

            for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol=-1;deltacol<=1;deltacol++){
                    if((deltarow==-1 and deltacol==-1) or (deltarow==-1 and deltacol==1) or (deltarow==1 and deltacol==-1) or (deltarow==1 and deltacol==1))
                    continue;

                    int nr=row+deltarow;
                    int nc=col+deltacol;
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
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count(0);
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }

        return count;
    }
};