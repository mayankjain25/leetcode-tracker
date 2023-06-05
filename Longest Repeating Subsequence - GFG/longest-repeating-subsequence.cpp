//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string x){
		    // Code here
		    string y = x;
		    int n = x.size();
		    
		    int ans = 0;
		    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(x[i-1]==y[j-1] and i!=j){
		                dp[i][j] = 1 + dp[i-1][j-1];
		                ans = max(ans, dp[i][j]);
		            }
		            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends