class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto it:edges){
            int u = it[0], v=it[1], w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<vector<int>>dist(n, vector<int>(n, 1e9));

        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i==j) dist[i][j]=0;

        for(int i=0;i<n;i++){
            pq.push({0,i});

            while(!pq.empty()){
                auto item = pq.top();
                pq.pop();

                int currDist = item.first;
                int currNode = item.second;

                for(auto it:adj[currNode]){
                    int edgeWt = it.second;
                    int newNode = it.first;

                    if(currDist + edgeWt < dist[i][newNode]){
                        dist[i][newNode] = currDist + edgeWt;
                        pq.push({dist[i][newNode], newNode});
                    }
                }
            }
        }

        for(auto it:dist){
            for(auto it1:it) cout<<it1<<" ";
            cout<<endl;
        }


        int ans = 0, mini = INT_MAX;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt++;
            }
            if(mini>=cnt){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
    }
};