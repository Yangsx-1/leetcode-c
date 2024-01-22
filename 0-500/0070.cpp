class Solution {
public:
    int climbStairs(int n) {
        int a = 1 ,b = 1, c = 1;
        for(int i = 0; i < n - 1; ++i){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// finished in 2024.1.22, first use dynamic programming
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int last1 = 1, last2 = 2;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            ans = last1 + last2;
            last1 = last2;
            last2 = ans;
        }
        return ans;
    }
};
