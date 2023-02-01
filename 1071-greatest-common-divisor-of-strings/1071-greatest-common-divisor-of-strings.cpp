class Solution {
public:

    bool valid(string str1, string str2, int k){
        int n1 = str1.size(),n2=str2.size();
        if(n1%k >0 or n2%k >0) return false;
        else{
            string base = str1.substr(0,k);
            int l1=n1/k,l2=n2/k;
            return str1==join(base,l1) and str2==join(base,l2);
        }
    }

    string join(string str, int k){
        string ans="";
        for(int i=0;i<k;i++) ans+=str;
        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        for(int i=min(str1.size(),str2.size());i>=1;i--){
            if(valid(str1,str2,i)){
                return str1.substr(0,i);
            }
        }

        return "";
    }
};