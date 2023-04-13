class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l =1, r = 1;
        int res = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
          l = l * nums[i];
          r = r * nums[n - i - 1];
          res = max(res, max(l,r));
          if(l==0 ) l = 1;
          if(r==0) r = 1;
        }


        return res;
    }
};