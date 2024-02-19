// finished in 2024.2.19
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op1, op2;
                switch(s[0]) {
                    case '+':
                        op2 = st.top();
                        st.pop();
                        op1 = st.top();
                        st.pop();
                        st.push(op1+op2);
                        break;
                    case '-':
                        op2 = st.top();
                        st.pop();
                        op1 = st.top();
                        st.pop();
                        st.push(op1-op2);
                        break;
                    case '*':
                        op2 = st.top();
                        st.pop();
                        op1 = st.top();
                        st.pop();
                        st.push(op1*op2);
                        break;
                    case '/':
                        op2 = st.top();
                        st.pop();
                        op1 = st.top();
                        st.pop();
                        st.push(op1/op2);
                        break;
                }
            } else {
                st.push(stoi(s));
            }
            
        }
        return st.top();
    }
};