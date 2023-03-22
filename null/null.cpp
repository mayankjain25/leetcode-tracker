class Solution {
public:
    bool bfs(int i, vector<int>&vis, vector<vector<int>>&graph){
        queue<int>q;
        q.push(i);
        vis[i] = 0;

        while(!q.empty()){
            auto val = q.front();
            q.pop();

            for(auto node:graph[val]){
                if(vis[node]==-1){
                    q.push(node);
                    vis[node] = !vis[val];
                }
                else{
                    if(vis[node]==vis[val]) return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);

        for(int i=0;i<graph.size();i++){
            if(color[i]==-1 and bfs(i,color,graph)==false) return false;
        }

        return true;
    }
};