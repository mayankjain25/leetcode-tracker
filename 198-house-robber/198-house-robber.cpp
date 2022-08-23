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
        vector<int>dp(nums.size()+1,-1);
        return f(0,nums,nums.size(),dp);
    }
};