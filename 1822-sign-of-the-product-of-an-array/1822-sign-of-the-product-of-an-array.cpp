class Solution {
public:
    int signFunc(long long prd){
        return (prd>0)?1:((prd<0)?-1:0);
    }
    int arraySign(vector<int>& nums) {
        long long product = 1;
        int ans = 1;
        
        for(int i=0;i<nums.size();i++){
            ans*=signFunc(nums[i]);
        }

        return ans;
    }
};