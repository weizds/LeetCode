class MedianFinder {
public:
    MedianFinder() {
    }
    void addNum(int num) {
        if(pq_min.empty()) {
            pq_min.push(num);
            return;
        }
        if(num >= pq_min.top()){
            pq_min.push(num);
        }else{
            pq_max.push(num);
        }
        if((pq_min.size() - 1) > pq_max.size()) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
        if(pq_max.size() > pq_min.size()) {
            pq_min.push(pq_max.top());
            pq_max.pop();
        }
    }
    
    double findMedian() {
        if((pq_min.size() + pq_max.size()) % 2 == 1) {
            return pq_min.top();
        }else{
            return (pq_min.top() + pq_max.top()) / 2.;
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq_min;
    priority_queue<int> pq_max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */