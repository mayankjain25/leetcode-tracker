class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>&board, vector<vector<bool>>&vis){
        vis[row][col] = true;
        int n = board.size(),m=board[0].size();

        vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and board[nr][nc]=='O') dfs(nr,nc,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<m;i++){
            //first row
            if(board[0][i]=='O' and !vis[0][i]){
                dfs(0,i,board,vis);
            }

            //last row
            if(board[n-1][i]=='O' and !vis[n-1][i]){
                dfs(n-1,i,board,vis);
            }
        }

        for(int i=0;i<n;i++){
            //first col
            if(board[i][0]=='O' and !vis[i][0]) dfs(i,0,board,vis);

            //last col
            if(board[i][m-1]=='O' and !vis[i][m-1]) dfs(i,m-1,board,vis);
        }     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O') board[i][j]='X';
            }
        }
        
        // return ans;
    }
};