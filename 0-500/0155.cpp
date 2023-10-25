class MinStack {
    stack<int> num;
    stack<int> mini;
public:
    MinStack() {
        mini.push(INT_MAX);
    }
    
    void push(int val) {
        num.push(val);
        mini.push(min(val,mini.top()));
    }
    
    void pop() {
        num.pop();
        mini.pop();
    }
    
    int top() {
        return num.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

// 可以使用辅助栈，但如果只用一个栈，可以用栈来保存差值
// 必须使用long long，否则可能int溢出
// finished in 2023.10.25
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if (st.empty()) {
            min_value = static_cast<long long>(val);
            st.push(0);
        } else {
            long long diff = static_cast<long long>(val) - min_value;
            st.push(diff);
            if (diff < 0) {
                min_value = static_cast<long long>(val);
            }
        }
    }
    
    void pop() {
        if (st.top() >= 0) {
            st.pop();
        } else {
            min_value = min_value - st.top();
            st.pop();
        }
    }
    
    int top() {
        if (st.top() < 0) return min_value;
        else return st.top() + min_value;
    }
    
    int getMin() {
        return min_value;
    }

private:
    long long min_value;
    stack<long long> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */