class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>st={'a','e','i','o','u'};
        int n = s.size();
        int low = 0, high =0;
        int cnt = 0 , ans = 0;
        while(high<n){
            int sz = high - low + 1;
            if(st.find(s[high])!=st.end())cnt++;
            if(sz<k) high++;
            else if(sz==k){
                ans = max(ans, cnt);
                if(st.find(s[low])!=st.end()) cnt--;
                low++;
                high++;
            }
        }

        return ans;
    }
};