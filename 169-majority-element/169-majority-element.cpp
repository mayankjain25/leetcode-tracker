class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=floor(nums.size()/2);
        map<int,int>m;
        for(auto it:nums)m[it]++;
        
        for(auto it:m){
            if(it.second>res) return it.first;
        }
        
        return -1;
    }
        
};