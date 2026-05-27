class Solution {
public:
    int brute(string word) {
        // TC : O(N) , SC : O(26+52)
        int cnt = 0;
        unordered_set<char> st;
        vector<bool> ban(26, false);
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                if (ban[ch - 'a'])
                    continue;
                char up = 'A' + (ch - 'a');
                if (st.count(up) && st.count(ch)) {
                    ban[ch - 'a'] = true;
                    cnt--;
                } else if (st.count(ch) == 0) {
                    if (st.count(up)) {
                        ban[ch - 'a'] = true;
                    } else {
                        st.insert(ch);
                    }
                }
            } else {
                if (ban[ch - 'A'])
                    continue;
                char low = 'a' + (ch - 'A');
                if (st.count(low) && st.count(ch) == 0) {
                    cnt++;
                }
                st.insert(ch);
            }
        }
        return cnt;
    }
    int optimal(string word) {
        // TC : O(N+26),SC : O(26+26)
        int cnt = 0;
        vector<int> small(26, -1), up(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z')
                small[ch - 'a'] = i;
            else if (up[ch - 'A'] == -1)
                up[ch - 'A'] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (small[i] != -1 && up[i] != -1) {
                cnt += (small[i] < up[i]);
            }
        }
        return cnt;
    }
    int numberOfSpecialChars(string word) {
        return optimal(word);
        return brute(word);
    }
};