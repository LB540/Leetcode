class Solution {
public:
    
    typedef long long ll;
    
    bool possible(vector<int>& batteries,ll mid, int n) {
        ll req_min = n*mid;
        
        for(int i=0;i<batteries.size();i++) {
            req_min-=min((ll)batteries[i],mid);
            if(req_min<=0) return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll low = LLONG_MAX;
        ll total = 0;
        for(int i=0;i<batteries.size();i++) {
            low = min((ll)batteries[i],low);
            total+=batteries[i];
        }
        ll right = total/n;
        ll result =0;
        while(low<=right) {
            ll mid = low + (right-low)/2;
            if(possible(batteries,mid,n)) {
                result = mid;
                low = mid+1;
            }else {
                right = mid-1;
            }
        }
        return result;
    }
};