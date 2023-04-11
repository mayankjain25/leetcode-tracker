class Solution {
public:
    string performOperation(string s){
        stack<char>st;

        for(int i=0;i<s.size();i++){
            if(s[i]!='#')st.push(s[i]);
            else{
                if(!st.empty()) st.pop();
            }
        }

        string newWord;

        while(!st.empty()){
            newWord = st.top() + newWord;
            st.pop();
        }

        return newWord;
    }
    bool backspaceCompare(string s, string t) {
        return performOperation(s)==performOperation(t);
    }
};