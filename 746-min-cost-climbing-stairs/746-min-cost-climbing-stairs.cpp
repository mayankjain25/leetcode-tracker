class Solution {
public:
    
    int findMinCost(int index, vector<int>&cost,vector<int>&dp){
        if(index>=cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        
        int l=findMinCost(index+1,cost,dp) + cost[index];
        int r=findMinCost(index+2,cost,dp) + cost[index];
        
        return dp[index]=min(l,r);
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(findMinCost(0,cost,dp),findMinCost(1,cost,dp));
    }
};