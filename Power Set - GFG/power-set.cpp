//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string>ans;
	    void solve(string in, string op){
	        if(in.size()==0){
	            if(op!="") ans.push_back(op);
	            return;
	        }

	        string op1=op;
	        string op2=op;
	        op2.push_back(in[0]);
	        in.erase(in.begin());
	        solve(in,op1);
	        solve(in,op2);
	        return;
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    string op="";
		    solve(s,op);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends