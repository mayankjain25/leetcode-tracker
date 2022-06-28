class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>1)
                ans+=m[nums[i]]-1;
            }
        return ans;
    }
};