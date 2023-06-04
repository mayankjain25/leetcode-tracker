//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string x, string y) 
	{ 
	    // Your code goes here
	    int n = x.size(), m = y.size();
	    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++)
	        {
	            if(x[i-1]==y[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	        }
	    }
	    
	    int len = dp[n][m];
	    
	    return (n - len) + (m-len);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends