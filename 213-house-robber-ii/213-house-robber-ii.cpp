class Solution {
public:
    
    int f(vector<int>&nums, int start, int end){
        int prev1=nums[start],prev2=0,cur_i;
        int n=nums.size();
        for(int i=start+1;i<=end;i++){
            
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
        
        return max(f(nums,0,n-2),f(nums,1,n-1));
    }
};