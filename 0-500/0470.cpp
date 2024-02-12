// finished in 2024.2.12
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ans = 41;
        while (ans >= 40) {
            ans = (rand7()-1) * 7 + rand7()-1;
        }
        return ans % 10 + 1;
    }
};