class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> ind(n + 1, 0);
        for (auto i : shifts) {
            if (i[2] == 0) {
                ind[i[0]] -= 1;
                ind[i[1] + 1] += 1;
            } else {
                ind[i[0]] += 1;
                ind[i[1] + 1] -= 1;
            }
        }
        for (int i = 1; i < n; i++) {
            ind[i] += ind[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int shift = (ind[i] % 26 + 26) % 26;
            s[i] = 'a' + ((s[i] - 'a' + shift) % 26);
        }
        return s;
    }
};