class Solution {
public:
    
    void helper(int ind,vector<int>&nums, vector<int>&temp,set<vector<int>>&v1){
        
    
        
        if(ind>=nums.size()){
            if(temp.size()>=2) v1.insert(temp);
            return;
            
        }
        
        if(temp.size()==0 || nums[ind]>=temp.back()){
            temp.push_back(nums[ind]);
            helper(ind+1,nums,temp,v1);
            temp.pop_back();
        }
        helper(ind+1,nums,temp,v1);
        
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>v1;
        helper(0,nums,temp,v1);
        
        return vector<vector<int>>(v1.begin(),v1.end());
        
    }
};