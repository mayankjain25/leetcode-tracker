class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax=0,curMin=0,maxSum=nums[0],minSum=nums[0],sum=0;
        
        for(auto it:nums){
            curMax=max(curMax+it,it);
            maxSum = max(maxSum,curMax);
            curMin=min(curMin+it,it);
            minSum=min(curMin,minSum);
            sum+=it;
        }
        
        if(sum==minSum) return maxSum;
        return max(maxSum, sum - minSum);
    }
};