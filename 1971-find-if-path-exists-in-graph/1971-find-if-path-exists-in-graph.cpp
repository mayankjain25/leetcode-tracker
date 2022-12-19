class Solution {
private:
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        //adjacency list
        unordered_map<int,vector<int>>graph;
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);            
        }
        
        //making a bfs traversal
        queue<int>q;
        vector<bool>vis(n,0); //visited array
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int curr=q.front();
            
            q.pop();
            
            if(curr==end) return true;
            
            //traversing the adjacency list for the current node
            
            for(auto node:graph[curr]){
                if(!vis[node]){
                    vis[node]=1;
                    q.push(node);
                }
            }
        }
        
        return false;
    }
};