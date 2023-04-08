class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({beginWord, 1});

        st.erase(beginWord);

        while(!q.empty()){
            string wd = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(wd==endWord) return steps;

            for(int i=0;i<wd.size();i++){
                char original = wd[i];

                for(char ch='a';ch<='z';ch++){
                    wd[i]=ch;

                    if(st.find(wd)!=st.end()){
                        st.erase(wd);
                        q.push({wd,steps+1});
                    }
                }

                wd[i] = original;
            }
        }

        return 0;
    }
};