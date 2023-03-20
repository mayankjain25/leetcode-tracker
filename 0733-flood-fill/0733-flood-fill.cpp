class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans;

        queue<pair<int,int>>q;
        q.push({sr,sc});

        vis[sr][sc] = true;
        // image[sr][sc] = color;

        while(!q.empty()){
            auto val = q.front();
            q.pop();

            vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nr = val.first + delrow[i];
                int nc = val.second + delcol[i];

                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and image[nr][nc]==image[sr][sc]){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                    image[nr][nc] = color;
                }
            }


        }

        image[sr][sc]=color;

        return image;
    }
};