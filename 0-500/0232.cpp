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
