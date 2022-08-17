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
        
        int dp[n][n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) dp[i][j]=0;
        }
        // return f(0,0,triangle.size(),triangle,dp);
        
        //for the base case
        vector<int>row(n,0),curRow(n,0);
        
        for(int j=0;j<n;j++) row[j]=triangle[n-1][j];
        
        //for tabulation
        for(int i=n-2;i>=0;i--){
            // row=triangle[i+1];
            
            for(int j=i;j>=0;j--){
                int down=0,downRight=INT_MAX;
                down=triangle[i][j]+row[j];
                downRight=triangle[i][j] + row[j+1];
                curRow[j]=min(down,downRight);
                
            }
            row=curRow;
        }
        
        return row[0];
}
};