//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(int row,int col, vector<vector<int>>&m, vector<vector<bool>>&vis, vector<string>&ans, int n, string temp){
        vis[row][col] = true;
        if(row==n-1 and col==n-1){
            ans.push_back(temp);
        }
        
        vector<int>delrow = {-1,0,1,0}, delcol = {0,1,0,-1};vector<char> dir = {'U','R','D','L'};
        
        for(int i=0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            
            if(nr>=0 and nc>=0 and nr<n and nc<n and !vis[nr][nc] and m[nr][nc]){
                temp+=dir[i];
                dfs(nr, nc, m, vis, ans, n ,temp);
                temp.pop_back();
                vis[nr][nc] = false;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<bool>>vis(n, vector<bool>(n,false));
        
        if(m[0][0]==0) return {"-1"};
        
        dfs(0,0,m,vis,ans,n,"");
        
        return ans;
        
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends