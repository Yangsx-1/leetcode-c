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
