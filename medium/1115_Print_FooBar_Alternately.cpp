class FooBar {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int count{0};
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk, [this]{ return count % 2 == 0;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++count;
            lk.unlock();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk, [this]{ return count % 2 == 1;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++count;
            lk.unlock();
            cv.notify_all();
        }
    }
};