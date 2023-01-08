class Solution {
public:
    bool areOccurrencesEqual(string s) {
       map<char,int>m;
        for(auto it:s) m[it]++;
        
        if(m.size()==1) return true;
        vector<int>v;
        for(auto it:m){
            v.push_back(it.second);
        }
        
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]!=v[i+1]) return false;
        }
        
        return true;
    }
};