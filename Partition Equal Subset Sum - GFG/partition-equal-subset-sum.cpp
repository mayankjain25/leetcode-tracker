//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool helper(int index, int sum, int arr[], vector<vector<int>>&dp){
        if(index==0){
            if(sum==0) return true;
            return false;
        }
        if(sum==0) return true;
        if(dp[index][sum]!=-1) return dp[index][sum];
        if(arr[index-1]<=sum){
            dp[index][sum] = helper(index - 1, sum - arr[index -1], arr, dp) || helper(index - 1, sum, arr, dp);
        }
        else{
            dp[index][sum] = helper(index -1, sum, arr ,dp);
        }
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr+n, 0);
        if(sum&1) return 0;
        int target = sum/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        return helper(n, target, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends