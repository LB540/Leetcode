class BrowserHistory {
public:
    vector<string> urls;
    int curr;
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        curr=0;
    }
    
    void visit(string url) {
        urls.erase(urls.begin()+curr+1,urls.end());
        urls.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr = max(0,curr-steps);
        return urls[curr];
    }
    
    string forward(int steps) {
        curr = min((int)urls.size()-1,steps+curr);
        return urls[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */