//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int helper(int index, int sum, int arr[], vector<vector<int>>&dp){
	   //  if(sum==0) return 1;
	    if(index==0){
	       if(sum==0 and arr[0]==0) return 2;
	       if(sum==0 or arr[0]==sum) return 1;
	       return 0;
	   }
	  
	   if(dp[index][sum]!=-1) return dp[index][sum];
	   int notPick = helper(index -1, sum, arr, dp);
	   int pick = 0;
	   if(arr[index]<=sum) pick = helper(index - 1, sum  - arr[index ], arr, dp);
	   return dp[index][sum] = (pick+notPick)%(1000000007);
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int numZeroes = 0;
        for(int i=0;i<n;i++) if(arr[i]==0) numZeroes++;
        int val = pow(2,numZeroes);
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return helper(n-1, sum, arr, dp)%(1000000007);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends