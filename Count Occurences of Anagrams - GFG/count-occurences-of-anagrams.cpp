//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	  vector<int>v1(26,0),v2(26,0);
	  int ans=0;
	  
	  int n = pat.size();
	  for(int i=0;i<n;i++){
	      v1[pat[i] - 'a']++;
	  }
	  
	  int low = 0, high = 0;
	  
	  while(high<txt.size()){
	      v2[txt[high] - 'a']++;
	      int size = high - low + 1;
	      if(size<n){
	          high++;
	      }
	      else if(size==n){
	          if(v1==v2) ans++;
	          v2[txt[low]-'a']--;
	          low++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends