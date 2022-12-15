class Solution {
private:
    int lengthLCS(string s1, string s2, int index1, int index2,vector<vector<int>>&dp){
        if(index1<0 or index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        
        if(s1[index1]==s2[index2]) return dp[index1][index2]=1 + lengthLCS(s1,s2,index1-1,index2-1,dp);
        
        return dp[index1][index2] = max(lengthLCS(s1,s2,index1-1,index2,dp),lengthLCS(s1,s2,index1,index2-1,dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1 +dp[i-1][j-1];
        
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
            
        return dp[n][m];
    }
};