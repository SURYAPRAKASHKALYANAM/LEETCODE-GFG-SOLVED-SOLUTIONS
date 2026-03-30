class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> eveFreq(26, 0), oddFreq(26, 0);
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            if (i & 1) {
                oddFreq[s1[i] - 'a']++;
                oddFreq[s2[i] - 'a']--;
            } else {
                eveFreq[s1[i] - 'a']++;
                eveFreq[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (eveFreq[i] != 0 || oddFreq[i] != 0)
                return false;
        }
        return true;
    }
};