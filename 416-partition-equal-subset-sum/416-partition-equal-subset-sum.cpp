class Solution {
public:
    
    int f(int ind, int target, vector<int>&nums,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0){
            return nums[0]==target;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool notPick=f(ind-1,target,nums,dp);
        bool pick=false;
        if(nums[ind]<=target) pick=f(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target]=pick or notPick;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        if(sum%2!=0) return false;
        else return f(n-1,sum/2,nums,dp);
        
       
        
    
    }
};