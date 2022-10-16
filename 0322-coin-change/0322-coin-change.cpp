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
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int notTake = 0 + dp[i-1][j];
                int take=1e9;
            if(coins[i]<=j) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take, notTake);
            }
             
        }
      
       int ans=dp[coins.size()-1][amount];
        if(ans>=1e9) return -1;
        return dp[coins.size()-1][amount];
    }
};