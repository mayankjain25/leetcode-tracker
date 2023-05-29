//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(int index, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(sum==0) return true;
        if(index==0){
            if(sum==0) return true;
            return false;
        }
        if(dp[index-1][sum]!=-1) return dp[index-1][sum];
        bool pick, notpick;
        if(arr[index-1]<=sum){
            pick = helper(index - 1, sum - arr[index-1], arr,dp);
            notpick = helper(index - 1, sum, arr,dp);
            return dp[index-1][sum] = pick or notpick;
        }
        else{
            return dp[index-1][sum] = helper(index - 1, sum, arr,dp);
        }
        
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum + 1, -1));
        return helper(arr.size(), sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends