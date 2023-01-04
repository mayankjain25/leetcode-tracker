class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>tmp; int maxi=0;
        tmp.push_back(0);
        int index=0;
        for(auto it:gain){
            tmp.push_back(tmp[index]+ it);
            maxi=max(maxi,tmp[index]);
            index++;
            
        }
        
        return *max_element(tmp.begin(),tmp.end());
    }
};