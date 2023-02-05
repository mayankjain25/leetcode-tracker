class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>pre;
        int tot=0;
        for(auto it:words){
            string str=it;
            
            if(isVowel(str[0]) and isVowel(str[str.size()-1]))
                tot++;
            
            
            pre.push_back(tot);
        }
        
        for(auto it:pre) cout<<it<<" ";
        cout<<endl;
        
        for(auto it:queries){
            int l=it[0],h=it[1];
            if(l==0) ans.push_back(pre[h]);
            else{
                ans.push_back(pre[h] - pre[l-1]);
            }
        }       
        return ans;
    }
};
