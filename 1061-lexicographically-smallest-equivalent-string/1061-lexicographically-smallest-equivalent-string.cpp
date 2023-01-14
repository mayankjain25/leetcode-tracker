class Solution {
public:
    
    int parent[26];
    
    void make(int v){
        parent[v]=v;
    }
    
    int find(int v){
        if(v==parent[v]) return v;
        
        return parent[v] = find(parent[v]);
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a!=b){
            if(a<b) parent[b]=a;
            else parent[a]=b;
        }
        
        return;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
     
        string ans;
        for(int i=0;i<26;i++) parent[i]=i;
        
        for(int i=0;i<s1.size();i++) Union(s1[i]-'a',s2[i]-'a');
        
        for(int i=0;i<baseStr.size();i++) ans+=(char)(find(baseStr[i]-'a')+'a');
        
        return ans;
        
    }
};

