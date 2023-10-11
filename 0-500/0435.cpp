class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), []( auto&& u, auto&& v) { return u[0] > v[0]; }); //普通的cmp会导致拷贝构造超时，所以使用移动构造，右值引用
        int count=1;
        int lastl = intervals[0][0];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][1]<=lastl){
                count++;
                lastl = intervals[i][0];
            }
        }
        int ans = intervals.size() - count;
        return ans;
    }
};
