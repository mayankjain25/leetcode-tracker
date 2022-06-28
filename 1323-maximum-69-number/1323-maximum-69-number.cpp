class Solution {
public:
    int maximum69Number (int num) {
        vector<int>n;
        while(num>0){
            n.push_back(num%10);
            num/=10;
        }
        reverse(n.begin(),n.end());
        
        int d=n.size()-1;
        int ans=0,flag=1;
        
        for(int i=0;i<n.size();i++){
            if(n[i]==6 and flag){
                flag=0;
                n[i]=9;
                // break;
            }
            ans+=pow(10,d--)*n[i];
        }
        return ans;
    }
};