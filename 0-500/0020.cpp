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

// finished in 2023.10.23
class Solution {
public:
    vector<char> left = {'(', '{', '['};
    vector<char> right = {')', '}', ']'};
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            auto it = find(left.begin(), left.end(), s[i]);
            if (it != left.end()){
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                if (s[i] == right[0]) {
                    if (st.top() == left[0]) st.pop();
                    else return false;
                } else if (s[i] == right[1]) {
                    if (st.top() == left[1]) st.pop();
                    else return false;
                } else {
                    if (st.top() == left[2]) st.pop();
                    else return false;
                }
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};