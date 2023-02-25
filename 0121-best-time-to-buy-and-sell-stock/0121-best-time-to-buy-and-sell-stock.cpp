class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyInd=0, profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[buyInd]>prices[i]) buyInd=i;
            profit=max(profit,prices[i] - prices[buyInd]);
        }
        
        return profit;
    }
};