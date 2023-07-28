class LRUCache {
public:
    unordered_map<int,list<int>::iterator>address;
    unordered_map<int,int>mp;
    list<int>l;
    int siz;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        siz = 0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            siz--;
        }else if(siz == cap) {
            address.erase(l.back());
            mp.erase(l.back());
            l.pop_back();
            siz--;
        }
        
        siz++;
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */