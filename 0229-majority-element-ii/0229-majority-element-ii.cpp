class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // 1. Better Approach
        
        // unordered_map<int,int>ump;
        // vector<int>res;
        // for(int i=0;i<nums.size();i++) {
        //     ump[nums[i]]++;
        //     if(ump[nums[i]]==(nums.size()/3)+1 ) {
        //         res.push_back(nums[i]);
        //     }
        //     if(res.size()==2) break;
        // }
        // sort(res.begin(),res.end());
        // return res;
        
        // 2. Optimal Solution
        int n = nums.size();
        int cnt1=0,ele1;
        int cnt2=0,ele2;
        for(int i=0;i<nums.size();i++) {
            if(cnt1==0 && ele2!=nums[i]) {
                cnt1=1;
                ele1 = nums[i];
            }else if(cnt2==0 && ele1!=nums[i]) {
                cnt2=1;
                ele2 = nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else {
                cnt1--; cnt2--;
            }
        }
        // return {ele1,ele2};
        vector<int>ans;
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        
        if(cnt1 >= (n/3)+1)  ans.push_back(ele1);
        if(cnt2 >= (n/3)+1)  ans.push_back(ele2);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};