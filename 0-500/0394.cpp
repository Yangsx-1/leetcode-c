// 此解法非常巧妙，可以记住，finished in 2023.10.28
class Solution {
public:
    string decodeString(string s) {
        string r;
        stack<pair<int, int>> st;
        int count = 0;
        for (auto x : s){
            if (isdigit(x)){
                count = 10 * count + (x - '0');
            } else if (x == '[') {
                st.push({count, r.size()});
                count = 0;
            } else if (isalpha(x)) {
                r += x;
            } else if (x == ']') {
                int n = st.top().first;
                string str = r.substr(st.top().second, r.size() - st.top().second);
                for (int i = 0; i < n - 1; ++i) {
                    r += str;
                }
                st.pop();
            }
        }
        return r;
    }
};