class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;
        int n = s.size(),low=0,high=0;
        vector<int>v(26,0);

        while(high<n){
            v[s[high] - 'a']++;
            int size = high - low + 1;
            if(size<3){
                high++;
            }
            else if(size==3){
                bool flag=true;
                for(auto it:v) if(it>1){
                    flag = false;
                    break;
                } 
                if(flag) ans++;
                v[s[low] - 'a']--;
                low++;
                high++;
            }
        }
        return ans;
    }
};