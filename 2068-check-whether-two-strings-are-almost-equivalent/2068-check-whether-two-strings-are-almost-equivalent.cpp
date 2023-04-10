class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int>mp;

        for(auto it:word1) mp[it]++;
        for(auto it:word2)mp[it]--;

        for(auto it:mp){
            if(abs(it.second)>3) return false;
        }
        return true;
    }
};