class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
       vector<vector<int>> res;
        int left = 0, right = 0;
        while (left < s.size()) {
            while (s[left] == s[right]) right++;
            if (right - left >= 3) res.push_back({left, right-1});
            left = right;
        }
        return res;
    }
};