// finished in 024.1.28
// 二分查找
class Solution {
public:
    int mySqrt(int x) {
        double threshold = 0.1;
        double left = 0, right = x;
        double last_mid = 0;
        while (left < right) {
            double mid = (left + right) / 2;
            if (mid - last_mid < threshold) return mid;
            long long pow_mid = mid * mid;
            if (pow_mid == x) return mid;
            if (pow_mid > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return 0;
    }
};

// 牛顿迭代
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double threshold = 1e-7;
        double lastans = x;
        double ans = 0.5 * (lastans + x / lastans);
        while (fabs(ans - lastans) > threshold) {
            lastans = ans;
            ans = 0.5 * (lastans + x / lastans);
        }
        return ans;
    }
};
