class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = calendar.lower_bound({start, end});
        if(it != calendar.end() && it->first < end)
            return false;
        if(it != calendar.begin()) {
            --it;
            if(it->second > start)
            return false;
        }
        calendar.insert({start, end});
        return true;
    }
private:
    set<pair<int, int>> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */