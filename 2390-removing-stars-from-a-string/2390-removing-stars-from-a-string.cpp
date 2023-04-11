class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        int n = s.size();

        string ans;

        for(int i=0;i<n;i++){
            if(s[i]!='*')st.push(s[i]);
            else{
                if(!st.empty()) st.pop();
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(begin(ans),end(ans));
        return ans;
    }
};