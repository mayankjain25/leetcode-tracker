class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(26);
        
        for(auto it:magazine){
            v[it-'a']++;
        }
        
        for(auto it:ransomNote){
            v[it-'a']--;
            if(v[it-'a']<0) return false;
        }
        return true;
    }
};