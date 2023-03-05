class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n = mat.size(),m = mat[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            auto val = q.front();
            q.pop();

            int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nr = val.first.first + delrow[i];
                int nc = val.first.second + delcol[i];

                if(nr>=0 and nc>=0 and nc<m and nr<n and !vis[nr][nc]){
                    vis[nr][nc]=true;
                    q.push({{nr,nc},val.second+1});
                    ans[nr][nc] = val.second+1;
                }
            }
        }

        return ans;
    }
};