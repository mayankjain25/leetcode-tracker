class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans,temp;
        
        int n = intervals.size(),index=0;
        
        if(n==0) return {{newInterval[0],newInterval[1]}};
        
        while(index<n and intervals[index][1]<newInterval[0]){
            ans.push_back(intervals[index]);
            index++;
        }
        
        while(index<n and newInterval[1]>=intervals[index][0]){
            newInterval[0]=min(newInterval[0],intervals[index][0]);
            newInterval[1] = max(newInterval[1],intervals[index][1]);
            index++;
            // if() break;
        }
        ans.push_back(newInterval);
        while(index<n) {ans.push_back(intervals[index]);index++;}
            
        
        
        return ans;
    }
};