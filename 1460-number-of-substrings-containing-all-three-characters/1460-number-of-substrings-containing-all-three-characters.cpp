class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.size();
        // OPTIMAL O(N)
        int lastSeen[3] = {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < len; i++) {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                ans += 1 + (*min_element(lastSeen, lastSeen + 3));
            }
        }
        return ans;
        // O (2*N)  SPACE
        // int hash[3] = {1, 1, 1};
        // int l = 0, r = 0;
        // int cnt = 0;
        // int ans = 0;
        // while (r < len) {
        //     if (hash[s[r] - 'a'] > 0)
        //         cnt++;
        //     hash[s[r] - 'a']--;
        //     while (cnt >= 3) {
        //         hash[s[l] - 'a']++;
        //         if (hash[s[l] - 'a'] > 0)
        //             cnt--;
        //         l++;
        //     }
        //     ans += (l);
        //     r++;
        // }
        // return ans;
    }
};