//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // #define MOD 100000
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>dist(99999, 1e9);
        queue<pair<int,int>>q;
        // set<int>s;
        q.push({0,start});
        // s.insert(start);
        
        int mod = 100000;
        
        dist[start] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int number = it.second;
            // s.insert(number);
            // if(number==end) return level;
            
            for(auto elem:arr){
                int newNum = (number*elem) % mod;
                if(steps+1<dist[newNum]){
                    dist[newNum] = steps+1;
                    if(newNum==end) return steps+1;
                    q.push({steps+1,newNum});
                }
            
        }
        }
        
        return -1;
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends