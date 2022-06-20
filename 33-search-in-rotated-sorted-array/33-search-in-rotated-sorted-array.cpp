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
        if(v[start]<=v[end]) return binSearch(v,target,start,end);
        else{
          while(start<=end){
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            
            if(v[mid]<=v[prev] and v[mid]<=v[next]){
                index=mid;
                break;
            }
            else{
                if(v[start]<=v[end]) {index=start;break;}
                else if(v[start]<=v[mid]) start = mid+1;
                else if(v[mid]<=v[end]) end=mid-1;
            }
        }
          
        }
        
       if(target>=v[0]){
           start=0;
           end=index;
       }       
        else if(target<=v[v.size()-1]){
            start=index;
            end=v.size()-1;
        }
        return binSearch(v,target,start,end);
        
    }
    
};