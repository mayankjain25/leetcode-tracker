//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        int low=0,high=0;
        long ans=LONG_MIN,currSum=0;
        
        while(high<arr.size()){
            currSum+=arr[high];
            if(high - low + 1 < K){
                // currSum+=arr[high];
                high++;
            }
            else if((high-low+1)==K){
                ans = max(ans, currSum);
                currSum-=arr[low];
                low++;
                high++;
                // currSum+=arr[high];
                // ans = max(prevSum,currSum);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends