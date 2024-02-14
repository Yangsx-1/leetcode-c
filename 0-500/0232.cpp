class MyQueue {
private:
    stack<int> in,out;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int p = 0;
        if(!out.empty()){
            p = out.top();
            out.pop();
        }
        else{
            while(!in.empty()){
                int tmp = in.top();
                out.push(tmp);
                in.pop();
            }
            p = out.top();
            out.pop();
        }
        return p;
    }
    
    int peek() {
        int p = 0;
        if(!out.empty()){
            p = out.top();
        }
        else{
            while(!in.empty()){
                int tmp = in.top();
                out.push(tmp);
                in.pop();
            }
            p = out.top();
        }
        return p;
    }
    
    bool empty() {
        if(in.empty() && out.empty()){
            return true;
        }
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// finished in 2024.2.13
class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int top;
        if (!out.empty()) {
            top = out.top();
            out.pop();
        } else {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            top = out.top();
            out.pop();
        }
        return top;
    }
    
    int peek() {
        int top;
        if (!out.empty()) {
            top = out.top();
        } else {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            top = out.top();
        }
        return top;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */