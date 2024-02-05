// finished in 2023.10.26
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for(int i = 0; i < k; ++i) {
            while(!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[q.front()]);
        for(int i = k; i < n; ++i) {
            while(!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while(!q.empty() && q.front() < i - k + 1) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

// finished in 2024.2.5
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        q.push_back(0);
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            while (!q.empty() && q.front() <= i-k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        for (int i = 0; i < k-1; ++i) {
            ans.erase(ans.begin());
        }
        return ans;
    }
};