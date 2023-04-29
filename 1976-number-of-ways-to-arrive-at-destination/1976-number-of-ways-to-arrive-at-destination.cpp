class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<long long,long long>>>adj;

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int mod = (int)(1e9 + 7);

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        pq.push({0,0});

        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        ways[0] = 1;

        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();

            long long currDist = item.first;
            long long currNode = item.second;

            for(auto node:adj[currNode]){
                long long edgeWt = node.second;
                long long newNode = node.first;

                if(currDist + edgeWt < dist[newNode]){
                    dist[newNode] = currDist + edgeWt;
                    pq.push({dist[newNode],newNode});
                    ways[newNode] = ways[currNode];

                }
                else if(currDist + edgeWt == dist[newNode]){
                    ways[newNode] = (ways[newNode] + ways[currNode])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;

        // return -1;
    }
};