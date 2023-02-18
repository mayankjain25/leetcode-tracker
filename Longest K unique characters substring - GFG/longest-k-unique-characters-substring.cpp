//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>m;
    int low=0,high=0,n=s.size();
    int ans = -1;
    
    while(high<n){
        m[s[high]]++;
        int size = high - low + 1;
        if(m.size()<k){
            high++;
        }
        else if(m.size()==k){
            int size = high - low + 1;
            ans=max(ans,size);
            high++;
        }
        else if(m.size()>k){
            while(m.size()>k){
             
                m[s[low]]--;
                if(m[s[low]]==0) m.erase(s[low]);
                low++;
                size=high - low + 1;
                if(m.size()==k) {ans = max(ans, size);break;}
            }
            high++;
        }
    }
    
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends