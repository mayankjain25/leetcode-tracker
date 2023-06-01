//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int index, int target, int arr[],vector<vector<int>>&dp){
        if(target<=0 or (index)==0) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
        int pick=0, notPick = 0;
        
        if(index<=target){
            pick  = arr[index-1] + helper(index, target - index, arr,dp);
            notPick= helper(index - 1, target, arr,dp);
            
        }
        else notPick = helper(index - 1, target, arr,dp);
        return dp[index][target]=max(pick, notPick);
    }
    int cutRod(int price[], int n) {
        //code here
        int sz = sizeof(price)/sizeof(price[0]);
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(n, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends