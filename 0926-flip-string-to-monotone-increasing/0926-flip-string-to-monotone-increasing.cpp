class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n =s.size();
        vector<int>ones(n),zero(n);
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones[i]=(i==0?0:ones[i-1])+1;
            }
            else ones[i]=(i==0?0:ones[i-1]);
        }
        

        int curr,ans=INT_MAX;
        
        for(int i=0;i<=n;i++){
            curr=(i==0?0:ones[i-1]);
            curr+=(n-i) - (ones[n-1] -( i==0?0:ones[i-1]));
            ans=min(ans,curr);
        }
        
        return ans;
    }
    
};

