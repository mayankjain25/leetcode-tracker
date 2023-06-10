//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string str, int i, int j, vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(isPalindrome(str, i, j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        for(int k=i;k<j;k++){
            int temp = 1 + solve(str, i,k,dp) + solve(str, k+1,j,dp);
            ans = min(ans, temp);
        }
        
        
        return dp[i][j] = ans;
        
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i] = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(isPalindrome(str, i,j)) dp[i][j] = 0;
                else{
                    int ans = 1e9;
                    for(int k = i;k<j;k++){
                        int temp = 1 + dp[i][k] + dp[k+1][j];
                        ans = min(ans, temp);
                    }
                    
                    dp[i][j] = ans;
                }
            }
        }
        
        
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends