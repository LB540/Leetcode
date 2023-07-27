class BrowserHistory {
public:
    list<string>hist;
    list<string> :: iterator it;

    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        it = hist.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        // hist.erase(it+1,it.end());
        hist.erase(del,hist.end());
        hist.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while((it!=hist.begin() && steps--)) {
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while((it!=(--hist.end()) && steps--)) {
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */