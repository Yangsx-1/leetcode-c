// finished in 2024.2.5
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        int highbits = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i&(i-1)) == 0) {
                highbits = i;
            }
            bits[i] = bits[i-highbits] + 1;
        }
        return bits;
    }
};