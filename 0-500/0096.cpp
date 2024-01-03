class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 1; i <= n; ++i) {
            C = C * (4 * i - 2) / (i + 1);
        }
        return (int)C;
    }
};