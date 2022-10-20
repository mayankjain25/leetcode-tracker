class Solution {
public:
    
    int coinChange2(int ind, int amt, vector<int>&coins,vector<vector<int>>&dp){
         if(ind==0){
           if(amt%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
            
        int take=0;
        if(coins[ind]<=amt)
        take=coinChange2(ind, amt - coins[ind],coins,dp);
        int notTake=0+coinChange2(ind-1,amt,coins,dp);
        
            
        return dp[ind][amt]=take+notTake;
    }
    
    
    int change(int amount, vector<int>& coins) {

        int sum=0,n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return coinChange2(n-1,amount,coins,dp);
        
    }
};