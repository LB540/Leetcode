//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // 1. Brute Approach (O(n^2) time complexity)
        // long long res = 0;
        // for(int i=1;i<n;i++) {
            
        //     int left=arr[i];
        //     for(int j=0;j<i;j++) {
        //         left = max(left,arr[j]);
        //     }
            
        //     int right =arr[i];
        //     for(int j=i+1;j<n;j++) {
        //         right = max(right,arr[j]);
        //     }
            
        //     res+=min(left,right)-arr[i];
        // }
        // return res;
        
        // 2. Better Approach O(n)time + O(n)space
        // int prefix[n];
        // prefix[0] = arr[0];
        // for(int i=1;i<n;i++) {
        //     prefix[i] = max(prefix[i-1],arr[i]);
        // }
        
        // int suffix[n];
        // suffix[n-1] = arr[n-1];
        // for(int i=n-2;i>=0;i--) {
        //     suffix[i] = max(suffix[i+1],arr[i]);
        // }
        // long long res =0;
        // for(int i=1;i<n-1;i++) {
        //     res+=min(suffix[i],prefix[i])-arr[i];
        // }
    
        // return res;
        
        // 3. Optimal Approach O(n) time + O(1) space
        int leftmax=0,rightmax=0;
        int l=0,r=n-1;
        long long res = 0;
        while(l<=r) {
            if(arr[l]<=arr[r]) {
                if(arr[l]>leftmax) leftmax = arr[l];
                else res+= leftmax-arr[l];
                l++;
            } else {
                if(arr[r]>rightmax) rightmax = arr[r];
                else res+=rightmax-arr[r];
                r--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends