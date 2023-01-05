class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int window=0;
        
        for(int i=0;i<k;i++) window+=cardPoints[i];
        
        int ans=window,n=cardPoints.size();
        
        for(int i=k-1;i>=0;i--){
            window-=cardPoints[i];
            window+=cardPoints[n-k+i];
            ans=max(window,ans);
        }
        
        return ans;
    }
};