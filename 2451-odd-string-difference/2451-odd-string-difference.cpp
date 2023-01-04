class Solution {
private:
    bool findMatch(string &a, string &b){
        for(int i=0;i<a.size()-1;i++){
            if((a[i+1] - a[i]) != (b[i+1] - b[i]))return false;
        }
               return true;
    }
public:
    string oddString(vector<string>& words) {
        
        int matchFirst=0,index=0;
        for(int i=1;i<words.size();i++){
            if(findMatch(words[0],words[i])) matchFirst++;
            else index=i;
        }
        
        return matchFirst>0?words[index]:words[0];
    }
};