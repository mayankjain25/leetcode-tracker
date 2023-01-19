class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int,int>m;
        m[0]=1;
        int i=0;
        int sum=0,ans=0;
        while(i<nums.size()){
            sum+=nums[i];
            int val = ((sum%k)+k)%k;
            if(m.find(val)!=m.end()) ans+=m[val];
            m[val]++;
            i++;
        }
        
        return ans;
    }
};
