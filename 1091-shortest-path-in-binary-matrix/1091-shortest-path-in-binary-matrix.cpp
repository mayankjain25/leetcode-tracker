class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1) return -1;
        if(m-1 == 0 or n-1 ==0) return 1;
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{0,0}});

        vector<vector<int>>dist(n,vector<int>(m,1e5));

        dist[0][0] = 0;

        pair<int,int>destination = {n-1,m-1};

        while(!q.empty()){
            auto item = q.front();
            q.pop();

            int currDist = item.first;
            int currRow = item.second.first;
            int currCol = item.second.second;

            // vector<int>delrow={-1,0,1,0}, delcol = {0,1,0,-1};
            vector<int>delrow = {-1,-1,0,1,1,1,0,-1},delcol={0,1,1,1,0,-1,-1,-1};

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){

                    int newRow = currRow + i;
                    int newCol = currCol + j;

                    if(newRow>=0 and newCol>=0 and newRow<n and newCol<m and grid[newRow][newCol]==0 and currDist + 1 < dist[newRow][newCol]){
            
                            dist[newRow][newCol] = currDist + 1;
            
                        if(newRow == n-1 and newCol == m-1) return dist[newRow][newCol]+1;
                        q.push({dist[newRow][newCol],{newRow,newCol}});
                    }
                }
            }
        }

        return -1;
    }
};