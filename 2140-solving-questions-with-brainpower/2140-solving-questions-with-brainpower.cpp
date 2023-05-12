class Solution {
public:
      long long mostPoints(vector<vector<int>>& q) {
      
        vector<long long> dp(q.size(),-1);  
        dp[q.size()-1]=q[q.size()-1][0];  
        
        for(int i=q.size()-2;i>=0;i--)
        { 
            int skip=i+q[i][1]+1; 
            dp[i]=dp[i+1]; 
            
            if(skip<q.size() && dp[i]<dp[skip]+q[i][0])
            dp[i]=q[i][0]+dp[skip];
            
            else if(dp[i]<q[i][0])
                dp[i]=q[i][0];
        }
        
        return dp[0];
        
        
    }
};