// finished in 2024.2.14
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> hash; // <斜率, 点个数>
        int max_count = 0, same_y = 1;
        for (int i = 0; i < points.size(); ++i) {
            same_y = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][1] == points[j][1]) {
                    ++same_y;
                } else {
                    double dx = points[i][0]-points[j][0], dy = points[i][1]-points[j][1];
                    ++hash[dx/dy];
                }
            }
            max_count = max(max_count, same_y);
            for (auto item : hash) {
                max_count = max(max_count, 1 + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};