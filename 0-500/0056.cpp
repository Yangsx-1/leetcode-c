class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> out;
        out.push_back(intervals[0]);
        int p=0;
        int l = intervals.size();
        for(int i=1; i<l; ++i){
            if(intervals[i][0] <= out[p][1] && intervals[i][1] > out[p][1]){
                out[p][1] = intervals[i][1];
            }
            else if(intervals[i][0] > out[p][1]){
                out.push_back(intervals[i]);
                p++;
            }
        }
        return out;
    }
};

// finished in 2024.1.20
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 这里可以直接比较，如果传入一个lambda函数会很慢
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        auto last_vec = intervals[0];
        for (const auto &vec : intervals) {
            if (vec[0] <= last_vec[1]) {
                if (vec[1] <= last_vec[1]) {
                    continue;
                } else {
                    last_vec[1] = vec[1];
                }
            } else {
                ans.push_back(last_vec);
                last_vec = vec;
            }
        }
        ans.push_back(last_vec);
        return ans;
    }
};