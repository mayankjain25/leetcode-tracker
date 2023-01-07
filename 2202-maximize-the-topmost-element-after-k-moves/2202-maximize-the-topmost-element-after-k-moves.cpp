class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
       int n=nums.size();
        if(n==1 and k&1) return -1;
        if(k<2) return nums[k];
        if(k>=nums.size()){
            return *max_element(nums.begin(), nums.end() - (k==nums.size()));
        }
        return max(nums[k],*max_element(nums.begin(),nums.begin()+k-1));
    }
};