class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

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
            auto node = q.front();
            q.pop();

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    numCourses--;
                    q.push(it);
                }
            }
        }

        return numCourses==0;

        

    }
};