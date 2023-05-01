class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n, vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) matrix[i][j]=0;

            }
        }

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            matrix[u][v]=w;
            matrix[v][u] = w;
        }

        // for(auto it:matrix){
        //     for(auto it1:it) cout<<it1<<" ";
        //     cout<<endl;
        // }

        int ans = 0;
        for(int via = 0; via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    // if(matrix[i][j]<=distanceThreshold) ans = max(ans, i);
                }
            }
        }

        cout<<"-------------"<<endl;

        for(auto it:matrix){
            for(auto it1:it) cout<<it1<<" ";
            cout<<endl;
        }

        //checking for threshold values
        // vector<pair<int,int>> temp;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0; 
            // mini = INT_MAX;
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0 and matrix[i][j]<=distanceThreshold) cnt++;

            }
            if(mini>=cnt){
                mini = cnt;
                ans = i;
            }
            // temp.push_back({cnt,i});
        }

                                                   

        return ans;
    }
};