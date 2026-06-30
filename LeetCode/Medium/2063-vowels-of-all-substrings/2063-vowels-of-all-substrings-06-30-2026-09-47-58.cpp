class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0LL;
        int len = word.size();
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < len; i++) {
            if (s.count(word[i])) {
                ans += (1LL * (i + 1) * (len - i));
            }
        }
        return ans;
    }
};