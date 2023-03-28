class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(numCourses,0);
        vector<int>topo;

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                numCourses--;
                q.push(i);
            }
        }

        while(!q.empty()){
            auto val = q.front();
            q.pop();

            topo.push_back(val);

            for(auto node:adj[val]){
                indegree[node]--;
                if(indegree[node]==0){
                    numCourses--;
                    q.push(node);
                }
            }
        }

        return (numCourses==0)?topo:vector<int>();
    }
};