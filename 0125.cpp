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
