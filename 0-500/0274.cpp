// finished in 2024.2.20
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1);
        for (auto it : citations) {
            if (it >= n) {
                ++count[n];
            } else {
                ++count[it];
            }
        }
        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};