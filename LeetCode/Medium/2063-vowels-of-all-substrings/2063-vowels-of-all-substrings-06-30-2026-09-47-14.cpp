class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0LL;
        int len = word.size();
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < len; i++) {
            if (s.count(word[i])) {
                long long bef = i + 1;
                long long aft = len - i;
                ans += (bef * aft);
            }
        }
        return ans;
    }
};