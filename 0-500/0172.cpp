// finished in 2024.2.8
class Solution { // count the number of 5
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};