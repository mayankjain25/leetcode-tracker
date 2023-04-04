class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int high = 0, low = 0;

        unordered_map<char, int>m;

        int ans = 0;

        while(low<n){
            m[s[low]]++;
            if(m[s[low]]>1){
                m.clear();
                m[s[low]]=1;
                ans++;
            }
            low++;
        }

        return ans+1;
    }
};