// finished in 2024.2.19
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            ++freq[ch];
        }
        int m = freq.size();
        vector<int> nextvalid, rest;
        for (auto [_, v] : freq) {
            nextvalid.push_back(1);
            rest.push_back(v);
        }
        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;
            int minnextvalid = INT_MAX;
            for (int j = 0; j < m; ++j) {
                if (rest[j]) {
                    minnextvalid = min(minnextvalid, nextvalid[j]);
                }
            }
            time = max(time, minnextvalid);
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextvalid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) {
                        best = j;
                    }
                }
            }
            nextvalid[best] = time + n + 1;
            --rest[best];
        }
        return time;
    }
};