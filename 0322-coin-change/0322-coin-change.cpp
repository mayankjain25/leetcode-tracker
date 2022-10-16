class Solution {
public:
    
    int returnMinCoins(int ind, vector<int>&coins, int target, vector<vector<int>>&dp){
        if (ind==0){
            
            if(target%coins[ind]==0) return target/coins[ind] ;
            else return 1e9;
        };
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notTake = 0 + returnMinCoins(ind-1, coins, target,dp);
        int take=1e9;
        if(coins[ind]<=target) take=1+returnMinCoins(ind, coins, target -coins[ind],dp);
        
        return dp[ind][target]=min(take, notTake);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1,-1));
        int val=returnMinCoins(coins.size()-1,coins,amount, dp);
        return val>=1e9?-1:val;
    }
};