// finished in 2024.2.14
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, multiset<string>> mp;
        for (const auto& ticket : tickets) {
            mp[ticket[0]].insert(ticket[1]);
        }
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string tmp = st.top();
            if (mp[tmp].empty()) {
                ans.emplace_back(tmp);
                st.pop();
            } else {
                st.push(*mp[tmp].begin());
                mp[tmp].erase(mp[tmp].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};