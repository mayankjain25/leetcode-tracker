class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if(n==1) return a[0];

        int low = 0, high = n-1;
        int mid;

        while(low<=high){
            mid = low + (high - low)/2;
            if((mid%2==0 and a[mid] == a[mid+1]) or (mid%2!=0 and a[mid]==a[mid-1])){
                low = mid+1;
            }
            else high = mid - 1;
                 
            
        }

        return a[low];
    }
};