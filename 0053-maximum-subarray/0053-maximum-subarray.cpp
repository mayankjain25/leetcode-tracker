class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0],curMax=0;
        for(auto it:nums){
            curMax=max(curMax+it,it);
            maxSum=max(maxSum,curMax);
        }
        
        return maxSum;
    }
};