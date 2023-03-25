class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        if(current != history.size() - 1)
            history.erase(history.begin() + current + 1, history.end());
        history.push_back(url);
        current = history.size() - 1;
    }
    
    string back(int steps) {        
        current -= steps;
        if(current < 0)
            current = 0;
        return history[current];
    }
    
    string forward(int steps) {
        current += steps;
        if(current >= history.size())
            current = history.size() - 1;
        return history[current];
    }
private:
    vector<string> history;
    int current{0};
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */