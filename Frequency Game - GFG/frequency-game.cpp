//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        vector<vector<int>>buckets(n+1);
        
        for(auto it:mp){
            int count = it.second;
            int val = it.first;
            
            buckets[count].push_back(val);
            
        }
        
        for(int i=0;i<buckets.size();i++){
            if(buckets[i].size()!=0){
                sort(buckets[i].begin(),buckets[i].end(), greater<int>());
                return buckets[i][0];
            }
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends