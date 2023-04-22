class Solution {
public:
    int longestPalindromicSubsequence(int index,int index2,string s, string t,vector<vector<int>>&dp){
        if(index<0 or index2<0) return 0;

        if(dp[index][index2]!=-1) return dp[index][index2];
        
        if(s[index]==t[index2]) return dp[index][index2] = 1 + longestPalindromicSubsequence(index-1,index2-1, s, t,dp);
        else return dp[index][index2]= max(longestPalindromicSubsequence(index,index2-1,s,t,dp),longestPalindromicSubsequence(index-1,index2,s,t,dp));
    }
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());

        int n = s.size(), m = s1.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s1[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return s.size() - dp[n][m];
    }
};


