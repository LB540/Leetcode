class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1, r=10e7+5;
        int min_speed=INT_MAX;
        while(l<r) {
            int mid = l+(r-l)/2;
            double total_time = 0;
            for(auto d: dist) {
                if(total_time > (int)total_time) {
                    total_time = (double)((int)total_time+1);
                }
                total_time += ((double)(d))/((double)(mid));
            }
            if(total_time > hour) l = mid+1;
            else { 
                r = mid;
                min_speed = mid;
            }
        }
        return (l>10000000 ? -1:min_speed);
    }
};