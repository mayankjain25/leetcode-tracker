class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>copy=nums;
        
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            copy[(i+k)%n] = nums[i];
        }
        
        nums=copy;
    }
        
    
};



