class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>ump;
        for(int i=0;i<arr.size();i++) {
            ump[arr[i]]++;
        }
        unordered_set<int>ust;
        for(auto x: ump) {
            if(ust.count(x.second)>0) return false;
            ust.insert(x.second);
        }
        return true;
    }
};