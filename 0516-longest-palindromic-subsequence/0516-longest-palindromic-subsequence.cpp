class Solution {
private:
    int solver(string s, string t, int n, int m, vector<vector<int>>&dp){
        if(n==0 or m==0) return 0;

        if(dp[n][m]!=-1) return dp[n][m];

        if(s[n-1]==t[m-1]) return dp[n][m] = 1 + solver(s,t,n-1,m-1,dp);
        else return dp[n][m] =  max(solver(s,t,n-1,m,dp),solver(s,t,n,m-1,dp));
    }

    int findLCS(string s, string t){
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                } 
            }
        }
        return dp[n][m];
    }

public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());

        return findLCS(s,t);
    }
};