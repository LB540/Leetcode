//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		  //  1. Approach (Brute)
		    unordered_map<char,int>mp;
		  //  for(int i=0;i<A.length();i++) {
		  //      mp[A[i]]++;
		  //  }
// 		    vector<int>help;
// 		    string ans = "";
// 		    for(int i=0;i<A.length();i++) {
// 		       if(mp.find(A[i]) == mp.end()) {
// 		          // ans += A[i];
// 		           help.push_back(A[i]);
// 		           mp[A[i]]=1;
// 		       }else {
// 		           int ind = find(help.begin(),help.end(),A[i]) - help.begin();
// 		           if(ind<help.size()) {
// 		               help.erase(help.begin() + ind);
// 		           }
// 		       }
// 		       ans += help.empty()?'#':help.front();
// 		    }
// 		    return ans;
		
// 		2. Approach using queue
		    queue<int>help;
		    string ans = "";
		    for(int i =0;i<A.length();i++) {
		      //  if(mp.find(A[i])==mp.end()) {
		            help.push(A[i]);
		      //  }
		        mp[A[i]]++;
		    
		        while(!help.empty() && mp[help.front()]>1) {
		            help.pop();
		        }
		        
		        if(!help.empty()) {
		            ans+=help.front();
		        }else {
		            ans+='#';
		        }
		    }
		    return ans;
		}
        
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends