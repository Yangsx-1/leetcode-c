// finished in 2024.2.12
class Solution {
public:
    double quickMul(double x, long long n) {
        if (n == 0) return 1.0;
        double y = quickMul(x, n / 2);
        return n % 2 == 0 ? y*y : y*y*x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};