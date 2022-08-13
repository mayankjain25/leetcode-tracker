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
        vector<vector<int>>dp(i,vector<int>(j,-1));
        
        return f(i-1,j-1,grid,dp);
    }
};