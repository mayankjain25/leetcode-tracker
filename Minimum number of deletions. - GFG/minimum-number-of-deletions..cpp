//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string x, int n) { 
    //complete the function here 
    string  y = x;
    reverse(y.begin(),y.end());
    
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    return n - dp[n][n];
} 