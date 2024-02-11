class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator i = s.begin();
    while(i != s.end())
    {
        if (*i >= 'A' && *i <= 'Z')
        {
            *i = *i + 32;
            ++i;
        }
        else if (*i >= 'a' && *i <= 'z') ++i;
        else if (*i >= '0' && *i <= '9') ++i;
        else s.erase(i);
    }
    int l = s.size();
    bool flag = true;
    for (int i = 0, j = l - 1; i <= j; ++i, --j)
    {
        if (s[i] != s[j]) flag = false;
    }

    return flag;
    }
};

// finished in 2024.2.11
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};