class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int low=0,high=0,n = fruits.size();
        int ans=0;
        // if(fruits.size()==1) return 1;

        while(high<n){
            m[fruits[high]]++;
            if(m.size()<2){
                ans=max(ans, high - low + 1);
                high++;
            }
            else if(m.size()==2){
                ans = max(ans, high - low + 1);

        
                high++;
            }
            else if(m.size()>2){
                while(m.size()>2){
                    m[fruits[low]]--;
                    if(m[fruits[low]]==0) m.erase(fruits[low]);
                    low++;
                    if(m.size()==2) ans = max(ans, high - low + 1);
                }
                high++;
            }
        }

        return ans;
    }
};