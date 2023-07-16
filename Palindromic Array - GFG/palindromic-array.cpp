//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    string reverse(string str) {
        int n = str.length();
        for(int i=0;i<str.length()/2;i++) {
            swap(str[i],str[n-i-1]);
        }
        return str;
    }
    
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0;i<n;i++) {
    	    string val = to_string(a[i]);
    	    string val2 = reverse(val);
    	    if(val != val2) return false;
    	}
        return true;
        
    }
    
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends