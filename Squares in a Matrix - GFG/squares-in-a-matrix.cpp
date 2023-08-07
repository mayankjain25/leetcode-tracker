//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long squaresInMatrix(int m, int n) {
        
        if (n < m)
        	swap(m, n);
        
        long long ans = (long long)m*(long long)(m+1)*(long long)(2*m+1)/6 + (long long)(n-m)*(long long)m*(long long)(m+1)/2;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m,n;
        
        cin>>m>>n;

        Solution ob;
        cout << ob.squaresInMatrix(m,n) << endl;
    }
    return 0;
}
// } Driver Code Ends