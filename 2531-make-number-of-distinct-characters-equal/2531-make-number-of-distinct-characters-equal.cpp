class Solution {
public:
    
    void helper(unordered_map<char,int>&m, char insert,char remove){
        m[insert]++;
        m[remove]--;
        if(m[remove]==0) m.erase(remove);
    }
    
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int>m1,m2;
        for(auto it:word1) m1[it]++;
        for(auto it:word2) m2[it]++;
        
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(m1.count(i)==0 or m2.count(j)==0) continue;
                
                helper(m1,j,i);
                helper(m2,i,j);
                
                if(m1.size()==m2.size()) return true;
                
                helper(m1,i,j);
                helper(m2,j,i);
            }
        }
        
        return false;
    }
};