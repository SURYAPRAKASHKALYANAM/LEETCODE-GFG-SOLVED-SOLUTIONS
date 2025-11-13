class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int oneCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                oneCount++;
            } else if (s[i + 1] == '1' || (i + 1) == s.size()) {
                res += oneCount;
            }
        }

        return res;
    }
};