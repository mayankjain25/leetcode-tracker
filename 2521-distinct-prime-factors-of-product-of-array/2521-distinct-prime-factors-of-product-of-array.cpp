class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unsigned long long prod=1;
        set<int>s;
        
        for(auto it:nums) {
            int c=2;
        while(it>1){
            if(it%c==0) {s.insert(c);it/=c;}
            else c++;
            
        }
        }
        
        
        return s.size();
    }
};