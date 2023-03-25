class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if(mins.empty())
            mins.push(val);
        else
            mins.push(min(mins.top(), val));
    }
    
    void pop() {
        values.pop();
        mins.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> values;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */