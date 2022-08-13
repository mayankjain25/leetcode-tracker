class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 and j==0) return grid[i][j];
        if(i<0 or j<0) return INT_MAX/2;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j] + f(i-1,j,grid,dp);
        int left=grid[i][j] + f(i,j-1,grid,dp);
        
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size();
        int j=grid[0].size();
        // vector<vector<int>>dp(i,vector<int>(j,0));
        
        vector<int>prevRow(j,0);
        
        // dp[0][0]=grid[0][0];
        
        for(int x=0;x<i;x++){
            // currentRow={0};
         vector<int>currentRow(j,0);
            
            for(int y=0;y<j;y++){
                if(x==0 and y==0) currentRow[0]=grid[0][0];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(x>0)
                    up=grid[x][y] + prevRow[y];
                    if(y>0)
                    left=grid[x][y] + currentRow[y-1];
                    currentRow[y]=min(up,left);
                }
            }
            prevRow=currentRow;
        }
        
        return prevRow[j-1];
    }
};