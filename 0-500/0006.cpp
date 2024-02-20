// finished in 2024.2.20
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vec(numRows);
        int i = 0;
        while (i < s.size()) {
            int count = 0;
            while (count < numRows) {
                if (i >= s.size()) break;
                vec[count++] += s[i++];
            }
            count = numRows-2;
            while (count > 0) {
                if (i >= s.size()) break;
                vec[count--] += s[i++];
            }
        }
        string ans;
        for (const auto& s : vec) {
            ans += s;
        }
        return ans;
    }
};