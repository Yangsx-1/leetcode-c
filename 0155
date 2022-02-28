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
