class Solution {
private:
    bool isSelfDividing(int num){
        int copy=num;
        
        while(num>0){
            int d = num%10;
            if(d==0 or copy%d!=0
              ) return false;
            num/=10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)) ans.push_back(i);
        }
        
        return ans;
    }
};