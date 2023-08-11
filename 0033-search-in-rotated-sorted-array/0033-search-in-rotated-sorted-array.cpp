class Solution {
public:
    
    int help(vector<int>&arr,int start,int end,int target) {
        if(start>end) return -1;
        int mid = (start+end)/2;
        if(arr[mid] == target) return mid;
        
        if(arr[start]<=arr[mid]) {
            if(target>=arr[start] && arr[mid]>target) {
                end = mid-1;
            } else {
                start = mid+1;
            }    
            return help(arr,start,end,target);
        }
        
        if(arr[mid]<target && arr[end]>=target) {
            return help(arr,mid+1,end,target);
        }
        
        return help(arr,start,mid-1,target);
        
    }
    
    int search(vector<int>& nums, int target) {
        return help(nums,0,nums.size()-1,target);
    }
};