class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>v(n,0);
        int ans=0;
        
        for(int i=0;i<n;i++){
            v[i] = start + 2*i;
            ans^=v[i];
        }
        return ans;
    }
};