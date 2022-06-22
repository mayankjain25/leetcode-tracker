class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int start=0,end=v.size()-1;
        int n=v.size();
        if(n==1) return 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(mid>0 && mid < n-1){
                if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
                    return mid;
                }
                else{
                    if(v[mid]<v[mid-1]) end=mid-1;
                    else start=mid+1;
                }
            }
            else if(mid==0){
                if(v[mid]>v[mid+1]) return mid;
                else return mid+1;
            }
            else{
                if(v[mid]<v[n-2]){
                    return n-2;
                }
                else return n-1;
            }
        }
        
        return -1;
    }
};