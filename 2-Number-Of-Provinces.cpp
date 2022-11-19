    // Question Link: https://leetcode.com/problems/number-of-provinces/description/ 
    
    
    #include <bits/stdc++.h>
    using namespace std;
    
    class Solution {
        private:
        void dfs(int node,vector<int>adjLs[], vector<int>&visited){
            visited[node] = 1;

            for(auto it:adjLs[node]){
                if(!visited[it]) {
                    // visited[node]=1;
                    dfs(it,adjLs, visited);
                }
            }
        }
        public:
        int findCircleNum(vector<vector<int>>& isConnected) {
        int size= isConnected.size();
        vector<int>visited(size,0);
            int count=0;
            vector<int>adjLs[size];
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(isConnected[i][j]==1 && i!=j){
                        adjLs[i].push_back(j);
                        adjLs[j].push_back(i);
                    }
                }
            }

            for(int i=0;i<size;i++){
                if(visited[i]==0){
                    count++;
                    dfs(i,adjLs,visited);

                }
            }

            return count;
        }
    };


//Space Complexity: O(N) [for visited array] + O(N) [for recursion] = O(N)

//Time complexity: O(N) + O(V + 2E) [V = size or number of nodes]