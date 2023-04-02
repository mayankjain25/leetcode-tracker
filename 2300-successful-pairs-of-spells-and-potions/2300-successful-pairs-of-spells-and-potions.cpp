class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int>ans;

        sort(potions.begin(), potions.end());

        for(int i=0;i<n;i++){

            double checker = (double)success/spells[i];

            int index = lower_bound(potions.begin(),potions.end(),checker) - potions.begin();

            ans.push_back(m - index);
        }

        return ans;
    }
};