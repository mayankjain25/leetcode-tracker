class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int n = heights.size(), m = heights[0].size();

        pq.push({0,{0,0}});

        vector<vector<int>>dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;

        vector<int>delrow = {-1,0,1,0}, delcol={0,1,0,-1};
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();

            int currDiff = item.first;
            int row = item.second.first;
            int col = item.second.second;

            if(row==n-1 and col == m-1) return currDiff;

            for(int i=0;i<4;i++){
                int newRow = row + delrow[i];
                int newCol = col + delcol[i];

                if(newRow>=0 and newCol>=0 and newRow<n and newCol<m){
                    int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), currDiff);
                    if(newEffort<dist[newRow][newCol]){
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return 0;
    }
};