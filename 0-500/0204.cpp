// finished in 2024.2.6
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isprime(n, true);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isprime[i]) {
                ++ans;
                for (long long j = (long long)i * i; j < n; j+=i) {
                    isprime[j] = false;
                }
            }
        }
        return ans;
    }
};