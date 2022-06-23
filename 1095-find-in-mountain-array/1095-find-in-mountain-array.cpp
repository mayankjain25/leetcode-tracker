/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int binSearch(MountainArray &m, int target, int start, int end,int flag){
        while(start<=end){
            int mid=start+(end-start)/2;
            int val=m.get(mid);
            
            if(val==target) return mid;
            else{
                if(flag){
                    if(val>target){
                        end=mid-1;
                    }
                    else start=mid+1;
                }
                else{
                    if(val>target){
                        start=mid+1;
                    }
                    else end=mid-1;
                }
            }
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        
        //finding peak element
        
        int start=0,end=n-1;
            int index=0;
        
        
        while(start<=end){
            int mid=start+(end-start)/2;
            int val=mountainArr.get(mid);
            
            if(mid>0 and mid<n-1){
                int left=mountainArr.get(mid-1);
                int right=mountainArr.get(mid+1);
                if(val>left and val>right){
                    index=mid;
                  
                    break;
                }
                else{
                    if(val<left) end=mid-1;
                    else start=mid+1;
                }
            }
            else if (mid==0){
         
            int right=mountainArr.get(mid+1);
                if(val>right){
                    index=mid;
                    break;
                }
                else{
                    index=mid+1;
                    break;
                }
            }
            else if(mid==n-1){
                int left=mountainArr.get(mid-1);

                if(val<left){
                    index=n-2;
                
                }
                else index=n-1;
                break;
            }
        }
        
        // return index;
        
        int res1=binSearch(mountainArr,target,0,index,true);
        int res2=binSearch(mountainArr,target,index+1,n-1,false);
        
        return res1!=-1?res1:(res2!=-1?res2:-1);
        
    }
};