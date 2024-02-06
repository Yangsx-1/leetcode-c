// finished in 2024.2.6
class Solution {
public:
    int magicTower(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        long long init = 1, delay = 0;
        for (int num : nums) {
            if (num < 0) {
                q.push(num);
            }
            init += num;
            if (init <= 0) {
                ++ans;
                init -= q.top();
                delay += q.top();
                q.pop();
            }
        }
        init += delay;
        return init <= 0 ? -1 : ans;
    }
};