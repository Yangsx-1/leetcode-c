// finished in 2024.2.10
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        bool ifcircle = false;
        while (n != 1) {
            if (m.find(n) == m.end()) {
                m.insert(n);
                int tmp = 0;
                while (n > 0) {
                    tmp += pow((n % 10), 2);
                    n /= 10;
                }
                n = tmp;
            } else {
                ifcircle = true;
                break;
            }
        }
        return ifcircle ? false : true;
    }
};