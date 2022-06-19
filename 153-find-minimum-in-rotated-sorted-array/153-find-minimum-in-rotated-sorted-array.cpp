class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();
        int mid=-1;
        
        if(nums[start]<=nums[end]) return nums[start];
        
        while(start<=end){
            mid=start + (end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[mid]<=nums[next] and nums[mid]<=nums[prev]) return nums[mid];
            else{
                if(nums[start]<=nums[end]) return nums[start];
                else if(nums[start]<=nums[mid]){
                    start=mid+1;
                }
                else if(nums[mid]<=nums[end]) end=mid-1;
            }
        }
        
        return nums[mid];
    }
};