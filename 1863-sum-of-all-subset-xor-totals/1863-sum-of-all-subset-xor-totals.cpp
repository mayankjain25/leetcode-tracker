class Solution {
public:
    int findXORSum(vector<int>&tmp){
        if(tmp.size()==0) return 0;
        int v = tmp[0];
        
        for(int i=1;i<tmp.size();i++) v ^=tmp[i];
        
        return v;
        
    }
    
    void helper(vector<int>&nums, int index, int &sum,vector<int>tmp){
        
        if(index==nums.size()){
            sum+=findXORSum(tmp);
            return;
        }
        

        
        tmp.push_back(nums[index]);
        helper(nums,index+1,sum,tmp);
        tmp.pop_back();
        helper(nums,index+1,sum,tmp);
        
        
        
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        vector<int>tmp;
        int sum=0;
        helper(nums, 0, sum, tmp);
        return sum;
    }
};