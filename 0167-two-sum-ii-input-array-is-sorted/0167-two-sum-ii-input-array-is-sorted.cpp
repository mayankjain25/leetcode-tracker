class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int endIndex=numbers.size()-1;
        map<int,int>m;
        m[numbers[0]]=1;
        m[numbers[1]]=2;
        
        for(int i=2;i<numbers.size();i++){
            m[numbers[i]]=i+1;
            if(numbers[i]>target) {
                endIndex=i-1;
                break;
            }
            
        }
        
        int startPointer=0,endPointer=endIndex;
        
        for(int i=startPointer;i<=endPointer;i++){
            int sumToFind = target - numbers[i];
            if(m.count(sumToFind)>0){
                return {i+1,m[sumToFind]};
            }
        }
        
        return {0,0};
    }
};