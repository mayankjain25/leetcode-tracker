class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        unordered_map<int, vector<int>>adj;
        vector<int>indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }


        queue<int>q;
        vector<int>safeNodes;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            auto val = q.front();
            q.pop();

            safeNodes.push_back(val);

            for(auto it:adj[val]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};