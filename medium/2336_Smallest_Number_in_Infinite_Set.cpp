class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!s.empty()) {
            int val = *s.begin();
            s.erase(s.begin());
            return val;
        }else{
            return current++;
        }
    }
    
    void addBack(int num) {
        if(num == current - 1){
            --current;
        }else if(num < current){
            s.insert(num);
        }
    }
private:
    int current{1};
    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */