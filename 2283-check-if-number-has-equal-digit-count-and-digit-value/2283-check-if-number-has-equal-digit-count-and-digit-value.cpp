class Solution {
public:
    bool digitCount(string num) {
        map<char,int>m;
        
        for(auto it:num){
            m[it-'0']++;
        }
        
        for(int i=0;i<num.size();i++){
            cout<<m[i]<<" "<<num[i]-'0'<<endl;
            if(m[i]!=(num[i]-'0')) return false;
        }
        
        return true;
    }
};