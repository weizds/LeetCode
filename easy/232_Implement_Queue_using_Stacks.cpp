class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st_in.empty())
            front = x;
        st_in.push(x);
    }
    
    int pop() {
        if(st_out.empty()) {
            while(!st_in.empty()) {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        if(!st_out.empty()) {
            int top = st_out.top();
            st_out.pop();
            return top;
        }
        return -1;
    }
    
    int peek() {
        if(st_out.empty())
            return front;
        return st_out.top();
    }
    
    bool empty() {
        return st_in.empty() && st_out.empty();
    }
private:
    stack<int> st_in;
    stack<int> st_out;
    int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */