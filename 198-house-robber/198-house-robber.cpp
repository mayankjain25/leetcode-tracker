class Solution {
public:
    
    int f(int i, vector<int>&nums, int n, vector<int>&dp){
        if(i>=n) return 0;
        if(i==n-1) return nums[n-1];
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+f(i+2,nums,n,dp);
        int notPick=f(i+1,nums,n,dp);
        return dp[i]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size()+1,-1);
        vector<int>dp(nums.size()+1,0);
        int n=nums.size();
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int pick=-1e3,notPick=-1e3;
           pick=nums[i] + dp[i+2];
           notPick=dp[i+1];
            dp[i]=max(pick,notPick);
        }
        
        return dp[0];
        // return f(0,nums,nums.size(),dp);
    }
};