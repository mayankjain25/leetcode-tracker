class Solution {
public:
    
    
    
    
    int findCount(int index,vector<int>&ds){
        if(index==0) return 0;
        if(index==1) return 1;
        if(ds[index]!=-1) return ds[index];
        
        
        return ds[index] =findCount(index-1,ds)+findCount(index-2,ds);
    }
    
    int climbStairs(int n) {
        
        vector<int>v(n+2,-1);
        
        return findCount(n+1,v);
        
    }
};