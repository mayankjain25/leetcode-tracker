class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int>m;
        
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]++;
        }
        
        for(auto it:m){
            
            if(it.second>1) return it.first;
            
            }
             
        int n1=*min_element(nums1.begin(),nums1.end()),n2=*min_element(nums2.begin(),nums2.end());
        if(n1<n2) return n1*10 + n2;
        else return n2*10 + n1;
             
        
    }
};