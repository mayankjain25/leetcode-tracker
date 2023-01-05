class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        for(auto it:points) cout<<it[0]<<" "<<it[1]<<endl;
        int ans=1;
        int currActiveArrow=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>currActiveArrow){
                currActiveArrow = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};