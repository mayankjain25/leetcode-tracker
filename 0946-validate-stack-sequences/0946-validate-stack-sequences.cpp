class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;

        // st.push(pushed[0]);

        int popIndex = 0;
        int n = pushed.size();
        int pushIndex = 0;

        while(pushIndex<n){
            st.push(pushed[pushIndex]);

            pushIndex++;
            int topElement = st.top();
            
            while(!st.empty() and popped[popIndex]==st.top()){
                st.pop();
                popIndex++;
                
            }
        }



       return st.empty();
    }
};
