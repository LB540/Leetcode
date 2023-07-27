class Solution {
public:
    
    typedef long long ll;
    
    bool possible(vector<int>& batteries,ll mid,int n) {
        ll target_minutes = (ll)n*mid;
        
        // ll sum = 0;
        for(int i=0;i<batteries.size();i++) {
            target_minutes -= min((ll)batteries[i],mid);
            
            if(target_minutes<=0) {
                return true;
            }
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = LLONG_MAX;
        ll total = 0;
        
        
        for(int i=0;i<batteries.size();i++) {
            l = min(l,(ll)batteries[i]);
            total += batteries[i];
        }
        
        
        ll r = total/n;
        ll result= 0;
        while(l<=r) {
            ll mid = l + (r-l)/2;
            if(possible(batteries,mid,n)) {
                result = mid;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        return result;
    }
};