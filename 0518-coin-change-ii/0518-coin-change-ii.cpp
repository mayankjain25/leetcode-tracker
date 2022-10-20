class Solution {
public:

    int change(int amount, vector<int>& coins) {

        int sum=0,n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        vector<int>prev (amount + 1,0), curr(amount+1,0);
        
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0) prev[amt]=1;
            else prev[amt]=0;
        }
        
        for(int row=1;row<n;row++){
            curr=prev;
            for(int col=0;col<=amount;col++){
                int take=0;
                if(coins[row]<=col)
                take=curr[col - coins[row]];
                int notTake=prev[col];


                curr[col]=take+notTake;
            }
            prev=curr;
        }
        
        return prev[amount];
        
    }
};