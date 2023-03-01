class Solution {
public:
   void Merge(int i,int k,int j,vector<int>&nums)
    {
        int n1=k-i+1;
        int n2=j-k;
        vector<int>L(n1+1),R(n2+1);

        for(int x=0;x<n1;x++)
        {
            L[x]=nums[i+x];
        }
        L[n1]=INT_MAX;
        for(int x=0;x<n2;x++)
        {
            R[x]=nums[k+1+x];
        }
        R[n2]=INT_MAX;
        int x=0;
        int y=0;
        for(int ind=i;ind<=j;ind++)
        {
            if(L[x]<R[y])
            {
                nums[ind]=L[x];
                x=x+1;
            }

            else
            {
                nums[ind]=R[y];
                y=y+1;
            }
        }
    }
   
   
    void MergeSort(int i,int j,vector<int>&nums)
    {
        if(i<j)
        {
            int k=i+(j-i)/2;
            MergeSort(i,k,nums);
            MergeSort(k+1,j,nums);
            Merge(i,k,j,nums);
        }
    }
   
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(0,nums.size()-1,nums);
        return nums;
    }

    
    
   
};