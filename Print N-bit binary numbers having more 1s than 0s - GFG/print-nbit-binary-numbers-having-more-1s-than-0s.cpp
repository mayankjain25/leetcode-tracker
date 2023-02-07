//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	    
    
    bool hasValidPrefixes(string s){
        int one=0;
        
        int i = s.size();
        while(i--){
            string str = s.substr(0,i+1);
            one=0;
            for(auto it:str){
                if(it=='1') one++;
            }
            
            if(one<(str.size()-one)) return false;
        }
        
        return true;
    }
    void solve(int one, int zero, string op,int N, set<string>&ans){
        if(N==0){
             ans.insert(op);
            
            return;
            
        }
        
        string op1=op, op2 = op;
        op1.push_back('1');
        solve(one+1,zero,op1,N-1,ans);
        if(one>zero){
            op2.push_back('0');
            solve(one,zero+1,op2,N-1,ans);
        }
        
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    string output="1";
	    if(N==1) return {"1"};
	   // if(N==2) return {"11","10"};
	    int one = 1,zero=0;
	    set<string>ans;
	    solve(one,zero,output,N-1,ans);
	    vector<string>a1(ans.begin(),ans.end());
	    sort(a1.begin(),a1.end(),greater<string>());
	    return a1;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends