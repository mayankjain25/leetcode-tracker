//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void solve(string s, string op, set<string>&ans){
        if(s.size()==0){
            if(op[op.size()-1]==' ') return;
            ans.insert(op);
            return;
        }
        
        string op1=op;
        string op2=op;
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        op2.push_back(' ');
        s.erase(s.begin());
        solve(s,op1,ans);
        solve(s,op2,ans);
    }

    vector<string> permutation(string s){
        // Code Here
        set<string>ans;
        string op="";
        solve(s,op,ans);
        
        return vector<string>(ans.begin(),ans.end());
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends