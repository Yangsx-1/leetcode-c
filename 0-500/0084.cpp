// finished in 2023.10.24
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top();
                st.pop();
                int left = st.top() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[top]);
            }
            st.push(i);
        }
        return ans;
    }
};