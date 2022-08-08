class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int length = s.length();
        for(int i = 0; i < length; ++i){
            switch(s[i]){
                case '(':
                st.push(s[i]);
                break;
                case '[':
                st.push(s[i]);
                break;
                case '{':
                st.push(s[i]);
                break;
                case ')':
                if(st.empty() || st.top() == '{' || st.top() == '[') return false;
                else st.pop();
                break;
                case ']':
                if(st.empty() || st.top() == '{' || st.top() == '(') return false;
                else st.pop();
                break;
                case '}':
                if(st.empty() || st.top() == '(' || st.top() == '[') return false;
                else st.pop();
                break;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
