//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_set<int>ans;
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++) {
            ump[arr[i]]++;
        }
        for(auto x: ump) {
            if(ans.count(x.second)>0) return false;
            ans.insert(x.second);
        }
        // sort(ans.begin(),ans.end());
        // for(int i=1;i<ans.size();i++) {
        //     if(ans[i]==ans[i-1]) return false;
        // }
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends