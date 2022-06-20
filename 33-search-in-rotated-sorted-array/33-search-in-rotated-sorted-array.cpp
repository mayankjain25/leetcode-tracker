class Solution {
public:
    
    
    int binSearch(vector<int>&v,int target, int start, int end){
        int mid=-1,ans=-1;
      
        while(start<=end){
            mid=(start) + (end-start)/2;
            
            if(v[mid]==target){
                ans=mid;
                return ans;
            }
            else{
                if(v[mid]>target){
                    end=mid-1;
                }
                else if(v[mid]<target) start=mid+1;
            }
            
        }
            return ans;
        
    }
    int search(vector<int>& v, int target) {
        int ans=-1,n=v.size();
        
        int start=0,end=v.size()-1,index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(v[mid]==target){
                ans=mid;
                break;
            }
            else{
                
                //checking left half sort
                if(v[0]<=v[mid]){
                    if(target>=v[0] and target<=v[mid]){
                        end=mid-1;
                    }
                    else start=mid+1;
                }
                else{
                    if(target>=v[mid] and target<=v[end]){
                        start=mid+1;
                    }
                    else end=mid-1;
                }
            }
        }
        
        return ans;
        
    }
    
};