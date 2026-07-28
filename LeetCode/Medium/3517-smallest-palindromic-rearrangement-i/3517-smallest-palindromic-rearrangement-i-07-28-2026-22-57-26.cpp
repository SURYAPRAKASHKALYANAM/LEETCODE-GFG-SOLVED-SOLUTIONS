class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnts(26, 0);
        for (char& ch : s)
            cnts[ch - 'a']++;
        string ans = "";
        int odd = -1;
        for (int i = 0; i < 26; i++) {
            if (cnts[i] > 0) {
                if (cnts[i] & 1)
                    odd = i;
                ans += string((cnts[i] >> 1), 'a' + i);
            }
        }
        if (odd != -1) {
            ans = ans + string(1, 'a' + odd) + string(ans.rbegin(), ans.rend());
        } else {
            ans = ans + string(ans.rbegin(), ans.rend());
        }
        return ans;
    }
};