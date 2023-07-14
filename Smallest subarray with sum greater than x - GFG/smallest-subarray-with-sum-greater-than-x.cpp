//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i=0,j=i+1;
        int sum = arr[0];
        if(sum>x) return 1;
        int cnt=INT_MAX;
        sum+=arr[j];
        while(i<n && j<n) {
            if(x<sum) { 
                cnt = min(cnt,j-i+1);
                sum-=arr[i];
                i++;
            }else {
                j++;
                if(j<n)
                    sum+=arr[j]; 
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends