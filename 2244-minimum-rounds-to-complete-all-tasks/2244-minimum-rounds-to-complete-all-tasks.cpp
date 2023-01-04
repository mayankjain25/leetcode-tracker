class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(auto it:tasks) m[it]++;
        
        int ans=0;
        
        for(auto it:m) cout<<it.first<<" "<<it.second<<endl;
        
        for(auto it:m){
            if(it.second==1) return -1;
            else if(it.second%3==0) ans+=it.second/3;
            else ans+=it.second/3+1;
        }
        
        
        return ans;
        
    }
};