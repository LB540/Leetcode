class Solution {
public:
    
    void print(vector<int>&nums,int ind,int n,vector<int>&ele,vector<vector<int>>&ans) {
        if(ind>=n) {
            ans.push_back(ele);
            return;
        }
        ele.push_back(nums[ind]);
        print(nums,ind+1,n,ele,ans);
        ele.pop_back();
        print(nums,ind+1,n,ele,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ele;
        print(nums,0,nums.size(),ele,ans);
        return ans;
    }
};