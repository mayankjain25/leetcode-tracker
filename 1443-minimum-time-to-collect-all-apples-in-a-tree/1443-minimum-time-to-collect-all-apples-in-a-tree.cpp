class Solution {
public:
    
    int dfs(int node, int cost, vector<bool>&hasApple, map<int,vector<int>>&adjacencyList, map<int,bool>&visited){
        if(visited[node]) return 0;
        
        visited[node] = true;
        
        int childCost=0;
        
        for(auto child:adjacencyList[node]){
            childCost+=dfs(child,2,hasApple,adjacencyList,visited);
        }
        
        if(childCost==0 and hasApple[node]==false) return 0;
        
        return childCost+cost;
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,vector<int>>adjacencyList;
        map<int,bool>visited;
        
        for(auto edge:edges){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0,0,hasApple,adjacencyList,visited);
        
    }
};