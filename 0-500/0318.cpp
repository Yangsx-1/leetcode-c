// finished in 2024.2.12
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> masks(len);
        for (int i = 0; i < len; ++i) {
            string word = words[i];
            int wordlen = word.size();
            for (int j = 0; j < wordlen; ++j) {
                masks[i] |= (1 << word[j]-'a');
            }
        }
        int maxprod = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    maxprod = max(maxprod, int(words[i].size()*words[j].size()));
                }
            }
        }
        return maxprod;
    }
};