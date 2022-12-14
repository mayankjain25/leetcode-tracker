class Solution {
public:
    int f(vector<int>nums,int index,vector<int>&dp){
        if(index>=nums.size()) return 0;
        if(index==nums.size()-1) return nums[nums.size()-1];
        if(dp[index]!=-1) return dp[index];
        int pick=nums[index] + f(nums,index+2,dp);
        int notPick=f(nums, index+1,dp);
        return dp[index]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return f(nums,0,dp);
    }
};