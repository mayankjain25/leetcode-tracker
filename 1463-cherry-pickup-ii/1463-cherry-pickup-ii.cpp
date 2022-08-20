class Solution {
public:
    
    int f(int i, int j1, int j2, vector<vector<int>>&grid, int n, int m, vector<vector<vector<int>>>&arr){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e2;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(arr[i][j1][j2]!=-1) return arr[i][j1][j2];
        
        int maxi=0;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2){
                    maxi=max(maxi, grid[i][j1] + f(i+1,j1+dj1,j2+dj2,grid,n,m,arr));
                }
                else{
                  maxi=max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2,grid,n,m,arr));  
                } 
            }
        }
        
        return arr[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return f(0,0,m-1,grid,n,m,dp);
    }
};