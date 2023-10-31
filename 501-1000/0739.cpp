class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> maxtem(temperatures.size());
        int j = 0;
        for(int i=0; i<temperatures.size()-1; ++i){
            s.push(i);
            while(!s.empty() && temperatures[s.top()] < temperatures[i+1]){
                maxtem[s.top()] = i+1-s.top();
                s.pop();
            }
        }
        return maxtem;
    }
};

// finished in 2023.10.31
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};