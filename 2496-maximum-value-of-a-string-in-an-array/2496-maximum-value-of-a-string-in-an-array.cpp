#include <bits/stdc++.h>
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=0;
        for(auto it:strs){
            if(all_of(it.begin(),it.end(),::isdigit)) ans=max(ans, stoi(it));
            else ans=max(ans,(int)it.size());
        }
        
        return ans;
    }
};