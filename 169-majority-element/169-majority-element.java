class Solution {
    public int majorityElement(int[] nums) {
        int candidate=-1,count=0;
        
        for(int i=0;i<nums.length;i++){
            if(count==0){
                candidate=nums[i];
            }
            if(nums[i]==candidate) count++;
            else count--;
        }
        
        return candidate;
    }
}