class BrowserHistory {
public:
    list<string> browser;
    list<string> :: iterator itr;
    BrowserHistory(string homepage) {
        browser.push_back(homepage);
        itr = browser.begin();
    }
    
    void visit(string url) {
        auto curr = itr;
        curr++;
        browser.erase(curr, browser.end());
        browser.push_back(url);
        itr++;
    }
    
    string back(int steps) {
        while(itr != browser.begin() && steps>0){
            itr--;
            steps--;
        }
        return *itr;
    }
    
    string forward(int steps) {
        while(itr!= (--browser.end()) && steps > 0){
            steps--;
            itr++;
        }
        return *itr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */