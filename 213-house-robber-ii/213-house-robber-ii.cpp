class Solution {
public:
    
    int f(vector<int>&nums){
        int prev1=nums[0],prev2=0,cur_i;
        int n=nums.size();
        for(int i=1;i<n;i++){
            
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notPick=0+prev1;
            
            cur_i=max(pick,notPick);
            prev2=prev1;
            prev1=cur_i;
            
            
        }
        
        return prev1;
    }
    
    
    int rob(vector<int>& nums) {
        vector<int>v1,v2;
        int n=nums.size();
        if(n==1) return nums[0];
        
        for(int i=0;i<n;i++){
            if(i!=n-1) v1.push_back(nums[i]);
            if(i!=0) v2.push_back(nums[i]);
        }
        
        return max(f(v1),f(v2));
    }
};