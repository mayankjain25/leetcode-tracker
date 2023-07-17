//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0, high = n - 1;
	    int ans = INT_MAX, index=0;
	    int mid;
	    while(low<=high){
	        mid = low + (high - low)/2;
	        
	        if(arr[low]<=arr[mid]){
	           // ans = min(ans, low);
	            if(ans>arr[low]){
	                ans = arr[low];
	                index = low;
	            }
	            low = mid + 1;
	        }
	        else if(arr[mid]<=arr[high]){
	           // ans = min(ans, mid);
	           if(ans>arr[mid]){
	               ans = arr[mid];
	               index=mid;
	           }
	            high = mid - 1;
	        }
	    }
	    
	    return index;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends