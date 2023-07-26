class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=10e7+5;
        int min_speed = INT_MAX;
        while(l<r) {
            int mid = l + (r-l)/2;
            double t_time = 0;
            for(auto d: dist) {
                if((double)t_time>(int)t_time) t_time =(int)t_time+1;
                t_time = t_time + (double)d/(double)mid;
            }
            if(t_time>hour) {
                l=mid+1;
            }else {
                r=mid;
                min_speed = mid;
            }
        }
        if(l>10e7) {
            return -1;
        }
        return min_speed;
    }
};