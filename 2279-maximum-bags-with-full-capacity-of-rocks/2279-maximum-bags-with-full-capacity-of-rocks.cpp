class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        int ans=0;
        vector<int>diffArray;
        
        for(int i=0;i<n;i++){
            diffArray.push_back(capacity[i] - rocks[i]);
        }
        
        sort(diffArray.begin(),diffArray.end());
        
        for(int i=0;i<n and diffArray[i] - additionalRocks <=0;i++){
            ans++;
            additionalRocks -= diffArray[i];
        }
        
        return ans;
    }
};