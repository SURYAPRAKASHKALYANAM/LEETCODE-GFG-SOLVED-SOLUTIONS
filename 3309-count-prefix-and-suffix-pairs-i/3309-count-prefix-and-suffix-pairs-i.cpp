class Solution {
public:
    int isPrefixAndSuffix(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        for (int i = 0; i < n1; i++)
            if (str1[i] != str2[i] || str1[n1 - 1 - i] != str2[n2 - 1 - i])
                return 0;
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[j].size() >= words[i].size())
                    ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return ans;
    }
};