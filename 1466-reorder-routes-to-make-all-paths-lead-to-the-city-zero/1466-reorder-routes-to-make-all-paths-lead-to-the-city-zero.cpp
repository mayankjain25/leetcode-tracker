class Solution {
public:
    unordered_map<int, unordered_set<int>> out, in;
    int ans = 0;
    
    void dfs(int node) {
        for (int x: out[node]) {

            ans++; 

            in[x].erase(node);

            dfs(x);
        }
        for (int x:in[node]) {
			out[x].erase(node);

            dfs(x);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;

        for (auto x: connections) {
            out[x[0]].insert(x[1]);
            in[x[1]].insert(x[0]);
        }

        dfs(0);
        return ans;
    }
};