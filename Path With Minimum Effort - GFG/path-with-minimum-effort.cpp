//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        
        dist[0][0] = 0;
        
        vector<int>delrow={-1,0,1,0}, delcol={0,1,0,-1};
        
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();
            
            int diff = item.first;
            int row = item.second.first;
            int col = item.second.second;
            
            if(row==n-1 and col==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int newRow = row + delrow[i];
                int newCol = col + delcol[i];
                
                if(newRow>=0 and newCol>=0 and newRow<n and newCol<m){
                    int effort = max(abs(heights[newRow][newCol] - heights[row][col]), diff);
                    
                    if(effort<dist[newRow][newCol]){
                        dist[newRow][newCol] = effort;
                        pq.push({effort,{newRow, newCol}});
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends