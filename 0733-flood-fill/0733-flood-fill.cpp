class Solution {
public:
    void bfs(int sr, int sc, int color, vector<vector<int>>&image,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int initColor = image[sr][sc];
        image[sr][sc] = color;
        int n = image.size(),m = image[0].size();
        vis[sr][sc] = true;

        while(!q.empty()){
            auto val = q.front();
            cout<<val.first<<" "<<val.second<<endl;
            q.pop();

            //traversing the 4 directions

            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if((delrow==-1 and delcol==-1) or (delrow==-1 and delcol==1) or (delrow==1 and delcol==-1) or (delrow==1 and delcol==1)) 
                    continue;

                    int newRow = val.first + delrow;
                    int newCol = val.second + delcol;

                    if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and image[newRow][newCol]==initColor and !vis[newRow][newCol]){
                        image[newRow][newCol] = color;
                        q.push({newRow,newCol});
                        vis[newRow][newCol] = true;
                    }
                }
            }

            
        }

        // image[sr][sc] = color; 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(),m = image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        bfs(sr, sc, color,image,vis);

        return image;
    }
};