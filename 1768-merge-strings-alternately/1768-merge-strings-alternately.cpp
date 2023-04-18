class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), n3 = min(n1,n2);
        int i=0;
        string ans;
        while(i<n3){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);

            cout<<ans<<endl;
            i++;
        }

        ans+=n3==n2?word1.substr(n2):word2.substr(n1);
        return ans;

    }
};