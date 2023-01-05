class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)==string::npos) return -1;
        return haystack.find(needle);
    }
};