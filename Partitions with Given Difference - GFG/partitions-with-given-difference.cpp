//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int helper(int index, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(index==0){
            if(sum==0 and arr[0]==0) return 2;
            if(sum==0 or arr[0]==sum) return 1;
            return 0;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        int notPick = helper(index - 1, sum, arr, dp);
        int pick = 0;
        if(arr[index]<=sum) pick = helper(index - 1, sum - arr[index], arr, dp);
        return dp[index][sum] = (pick + notPick)%1000000007;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int target = (sum - d);
        if(target<0 or target&1) return 0;
        target/=2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return helper(n-1, target, arr, dp)%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends