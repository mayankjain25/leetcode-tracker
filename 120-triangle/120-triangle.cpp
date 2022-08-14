class Solution {
public:
    int f(int i, int j,int n, vector<vector<int>>&a, vector<vector<int>>&dp){
       
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=a[i][j]+f(i+1,j,n,a,dp);
        int downRight=a[i][j] + f(i+1,j+1,n,a,dp);
        
        return dp[i][j]=min(down,downRight);
        
        
    
    
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(triangle[n-1].size(),-1));
        return f(0,0,triangle.size(),triangle,dp);
}
};