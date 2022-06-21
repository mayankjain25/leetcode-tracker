class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int min=1e6+7;
        
        for(int i=0;i<arr.size()-1;i++){
            int v=abs(arr[i+1]-arr[i]);
            if(min>v){
                min=v;
                ans.clear();
            }
            if(v==min){
                vector<int>a={arr[i],arr[i+1]};
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};