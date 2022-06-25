class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int start=0,end=v.size()-1,mid=0;
        
        while(start<end){
            mid=start+(end-start)/2;
            
            
            if(mid>0 and mid<v.size()-1){
              if((mid%2==0 and v[mid]==v[mid+1])or(mid%2!=0 and v[mid]==v[mid-1])) start=mid+1;
            else end=mid;  
            }
            else if(mid==0){
                if(v[mid]==v[mid+1]) start=mid+1;
                else end=mid;
            }
            else if(mid==v.size()-1){
                if(v[mid]==v[mid-11]) end=mid-1;
                else start=mid+1;
            }
            
            
        }
        
        return v[start];
    }
};