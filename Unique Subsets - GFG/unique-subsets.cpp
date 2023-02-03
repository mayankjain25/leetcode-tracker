//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(vector<int>arr, vector<int>op,set<vector<int>>&ans){
        if(arr.size()==0){
            // if(op.size()==0) return;
            // sort(op.begin(),op.end());
            ans.insert(op);
            return;
        }
        
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(arr[0]);
        arr.erase(arr.begin());
        solve(arr,op1,ans);
        solve(arr,op2,ans);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        set<vector<int>>ans;
        sort(arr.begin(),arr.end());
        vector<int>op;
        solve(arr, op,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends