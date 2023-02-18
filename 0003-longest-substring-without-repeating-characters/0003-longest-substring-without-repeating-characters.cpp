class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int low=0,high=0,n=s.size();

        int ans = 0;

        while(high<n){
            m[s[high]]++;
            if(m[s[high]]==1){
                ans = max(ans, high - low + 1);
                high++;
            }
            else if(m[s[high]]>1){
                while(m[s[high]]!=1){
                    m[s[low]]--;
                    if(m[s[low]]==0) m.erase(s[low]);
                    low++;
                }
                high++;
            }
        }

        return ans;
    }
};